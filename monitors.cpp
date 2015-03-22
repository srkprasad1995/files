// $Smake: CC -O -o %F %f msecond.o random_int.o -lpthread -lm

// A solution to the dining philosophers problem, using pthreads, semaphores,
// and shared memory.

// Written 01/04/2000 by J. Senning
 
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//#include "msecond.h"
//#include "random_int.h"

using namespace std;

const int NumberOfPhilosophers	= 5;	// must be 5
const int MeanThinkTime		= 1000;	// average think time in milliseconds
const int MeanEatTime		= 750;	// average eating time in milliseconds

// Global (shared) variables

float totalTimeSpentWaiting	= 0.0;
int   totalNumberOfMealsServed	= 0;

//============================================================================

// Define a class based on POSIX semaphore functions.

#include <semaphore.h>

class Semaphore
{
private:
    sem_t _semaphore;

public:
    Semaphore( int value = 1 )	{ (void) sem_init( &_semaphore, 0, value ); };
   ~Semaphore( void )		{ (void) sem_destroy( &_semaphore ); };
    void wait( void )		{ (void) sem_wait( &_semaphore ); };
    void signal( void )		{ (void) sem_post( &_semaphore ); };
};

// Each chopstick is represented by a semaphore.  We also need a semaphore
// to control screen accesses so that only one thread at a time can write to
// it, and another semaphore to control modifications of the shared variables.

Semaphore chopstick[NumberOfPhilosophers];
Semaphore screen;
Semaphore mutex;

//============================================================================

// Define data and routines for screen management

static int  screen_row[NumberOfPhilosophers] = {  6,  2,  2,  6, 10 };
static int  screen_col[NumberOfPhilosophers] = { 31, 36, 44, 49, 40 };
static int  chopstick_row[NumberOfPhilosophers] = {  9,  4,  3,  4,  9 }; 
static int  chopstick_col[NumberOfPhilosophers] = { 35, 33, 40, 47, 45 };
static char chopstick_sym[NumberOfPhilosophers] = { '/', '\\', '|', '/', '\\' };

#define cls		"\033[H\033[J"
#define pos(row,col)	"\033[" << (row) << ";" << (col) << "H"

void initScreen( void )
// Draw an initial representation of the philosophers' "world" on the screen
{
    // Initialize for VT100 escape sequences.  Basically, we want to have
    // the screen updated after every character is output.

    cout.flags( cout.flags() | ios::unitbuf );

    // Draw rice bowl

    cout << cls;
    cout << pos( 6, 37 ) << "\\     /";
    cout << pos( 7, 37 ) << " \\___/ ";

    // Print philosopher numbers at their locations.

    for ( int i = 0; i < NumberOfPhilosophers; i++ )
    {
	cout << pos( screen_row[i], screen_col[i] ) << i;
	cout << pos( screen_row[i] + 1, screen_col[i] - 1 ) << "(0)";
	cout << pos( chopstick_row[i], chopstick_col[i] ) << chopstick_sym[i];
    }
    cout << pos( 13, 1 );
};

void drawThinking( int n )
// Display T for "thinking" at the appropriate location
{
    screen.wait();
    cout << pos( screen_row[n], screen_col[n] );
    cout << "\033[33mT\033[0m" << pos( 13, 1 );
    screen.signal();
};

void drawHungry( int n )
// Display H for "hungry" at the appropriate location
{
    screen.wait();
    cout << pos( screen_row[n], screen_col[n] );
    cout << "\033[34mH\033[0m" << pos( 13, 1 );
    screen.signal();
};

void drawEating( int n, int eatCount )
// Display E for "eating" and the meal count at the appropriate location
{
    screen.wait();
    cout << pos( screen_row[n], screen_col[n] );
    cout << "\033[31mE\033[0m" << pos( 13, 1 );
    cout << pos( screen_row[n] + 1, screen_col[n] - 1 );
    cout << "(" << eatCount << ")" << pos( 13, 1 );
    screen.signal();
};

void drawChopstickUp( int n )
// Display a blank where the chopstick should be if it where on the table
{
    screen.wait();
    cout << pos( chopstick_row[n], chopstick_col[n] );
    cout << " " << pos( 13, 1 );
    screen.signal();
};

void drawChopstickDown( int n )
// Display the chopstick on the table
{
    screen.wait();
    cout << pos( chopstick_row[n], chopstick_col[n] );
    cout << "\033[32m" << chopstick_sym[n] << "\033[0m" << pos( 13, 1 );
    screen.signal();
};

void drawDone( int n )
// Display D for "done" at the appropriate location
{
    screen.wait();
    cout << pos( screen_row[n], screen_col[n] );
    cout << "D" << pos( 13, 1 );
    screen.signal();
};

//============================================================================

// The Philosopher class.

class Philosopher
{
private:
    pthread_t	_id;
    int		_number;
    int		_timeToLive;

public:
    Philosopher( void ) { _number = -1; _timeToLive = 0; };
    Philosopher( int n, int t )	{ _number = n; _timeToLive = t; };
   ~Philosopher( void )		{};
    void getChopsticks( void );
    void releaseChopsticks( void );
    void start( void );
    void wait( void );
    friend void Philosopher_run( Philosopher* p );
};

void Philosopher::getChopsticks( void )
// To obtain his chopsticks, a philosopher does a semaphore wait on each.
// Alternating order prevents deadlock.
{
    if ( _number % 2 == 0 )
    {
	// even-numbered philosopher; pickup left then right...
	chopstick[( _number + 1 ) % NumberOfPhilosophers].wait();
	drawChopstickUp( ( _number + 1 ) % NumberOfPhilosophers );
	chopstick[_number].wait();
	drawChopstickUp( _number );
    } else {
	// odd-number philosopher; pickup right then left...
	chopstick[_number].wait();
	drawChopstickUp( _number );
	chopstick[( _number + 1 ) % NumberOfPhilosophers].wait();
	drawChopstickUp( ( _number + 1 ) % NumberOfPhilosophers );
    }
};

void Philosopher::releaseChopsticks( void )
// To release his chopsticks, a philosopher does a semaphore signal on each.
// Order does not matter.
{
    drawChopstickDown( _number );
    chopstick[_number].signal();
    drawChopstickDown( ( _number + 1 ) % NumberOfPhilosophers );
    chopstick[( _number + 1 ) % NumberOfPhilosophers].signal();
};

void Philosopher::start( void )
// Start the thread representing the philosopher  
{
    if ( _number < 0 )
    {
	cerr << "Philosopher::start(): Philosopher not initialized\n";
	exit( 1 );
    }
    if ( pthread_create( &_id, NULL, (void *(*)(void *)) &Philosopher_run,this ) != 0 )
    {
	cerr << "could not create thread for philosopher\n";
	exit( 1 );
    }
};

void Philosopher::wait( void )
// When called by the parent, this method will block until the philosopher's
// thread terminates.
{
    pthread_join( _id, NULL );
};

void Philosopher_run( Philosopher* philosopher )
// Simulate a philosopher - endlessly cycling between eating and thinking
// until his "life" is over.  Since this is called via pthread_create(), it
// must accept a single argument which is a pointer to something.  In this
// case the argument is a pointer to an array of two integers.  The first
// is the philosopher number and the second is the duration (in seconds)
// that the philosopher sits at the table.
{
    int n = philosopher->_number;
    int duration = philosopher->_timeToLive;
    int eatCount = 0;
    int totalHungryTime = 0;
    int becameHungryTime;
      
    int startTime = msecond();

    while( msecond() - startTime < duration * 1000 )
    {
	// Hungry
	
	becameHungryTime = msecond();
	drawHungry( n );
	philosopher->getChopsticks();
	
	// Eating
	
	totalHungryTime += ( msecond() - becameHungryTime );
	eatCount++;
	drawEating( n, eatCount );
	usleep( 1000L * random_int( MeanEatTime ) );
	philosopher->releaseChopsticks();
	
	// Think
	
	drawThinking( n );
	usleep( 1000L * random_int( MeanThinkTime ) );
    }
    
    // Done
    
    drawDone( n );
    
    mutex.wait();
    totalNumberOfMealsServed += eatCount;
    totalTimeSpentWaiting += ( totalHungryTime / 1000.0 );
    mutex.signal();

    pthread_exit( NULL );
};

//============================================================================

int main( int argc, char *argv[] )
{
    Philosopher p[NumberOfPhilosophers];

    // The duration is specified as the first parameter on the command line.
    // If it was not there then set the duration to 10.

    int duration = ( argc > 1 ? atoi( argv[1] ) : 10 );

    // Initalize the display and start the thread for each philosopher.
    
    initScreen();
    for ( int i = 0; i < NumberOfPhilosophers; i++ )
    {
	p[i] = Philosopher( i, duration );
	p[i].start();
    }

    // Wait for the philosophers to finish.
    
    for ( int i = 0; i < NumberOfPhilosophers; i++ )
    {
	p[i].wait();
    }

    // Produce the final report.
    
    cout << pos( 13, 1 );
    cout << "Total meals served = " << totalNumberOfMealsServed << "\n";
    cout << "Average hungry time = " <<
	( totalTimeSpentWaiting / totalNumberOfMealsServed ) << "\n";

    return 0;
};
