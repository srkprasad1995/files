#include<iostream>
#include<cstdio>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

using namespace std;

const int NumberOfPhilosophers	= 5;	// must be 5

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

Semaphore chopstick[NumberOfPhilosophers];
Semaphore mutex;

class Monitor
{
public:
	enum{thinking,hungry,eating} state[5];// data being protected by monitor
	Semaphore self[5]; // suspends a thread on a wait
	int waiters; // number of threads waiting on
				// a cvar (one for every condition)
	Semaphore lock; // controls entry to monitor
	Semaphore next; // suspends this thread when signaling another
	int nextCount; // number of threads suspended	

	void ConditionWait(int i)// Condition Wait
	{ // Condition Wait
		waiters += 1;
		if (nextCount > 0)
			next.wait(); // resume a suspended thread
		else
			lock.signal(); // allow a new thread in the monitor
			self[i].wait(); // wait on the condition
			waiters -= 1;
	}
	void ConditionSignal(int i) // Condition Signal
	{
		if (waiters > 0) 
		{ // don't signal cvar if nobody is waiting
			nextCount += 1;
			self[i].signal(); // Semaphore Signal
			next.wait(); // Semaphore Wait
			nextCount -= 1;
		}
	}

	
	void pickup(int i)
	{
		state[i] = hungry;
		test(i);
		if(state[i] !=eating)
			ConditionWait(i);
	}
	
	void putdown(int i)
	{
		state[i] = thinking;
		test((i+4)%5);
		test((i+1)%5);
	}
	
	void test(int i)
	{
		if(state[(i+4)%5] != eating && state[i] != hungry && state[(i+1)%5] !=eating)
		{
			state[i] = eating;
			ConditionSignal(i);
		}
	}

	void initialize() 
	{
		for(int i=0;i<5;i++)
			state[i] = thinking;
	}

	
}; // on next

int main()
{
	Monitor dp;
	dp.initialize();
	for(int i=0;i<5;i++)
	{
		dp.pickup(i);
		cout<< "im eating"<<i<<endl;
		dp.putdown(i);
	}
	return 0;
}
