#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include<limits.h>

void First_come_first_serve();
void Shortest_job_First_sort();
void priority_scheduling();
void round_robin();
void Shortest_remaining_time_first();


//Main function
int main()
{
	int ch;
		printf("Enter your option\n");
		printf("\n1. First_come_first_serve\n2. Shortest_job_First\n3. Shortest_remaining_time_first\n4. Priority\n5. Round Robin\n");
		printf("\nSelect Algorithm : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					First_come_first_serve();
					break;

			case 2:
					Shortest_job_First_sort();
					break;

      			case 3:
          				Shortest_remaining_time_first();
          				break;

			case 4:
					priority_scheduling();
					break;

			case 5:
					round_robin();
					break;


		}
}

//First come first serve method of scheduling

void First_come_first_serve()
{

int n,arrival[10],burst[10];
int t[10],w[10],g[10],i,m;
float avg_ta=0,avg_wt=0;

//Inititalisation
for(i=0;i<10;i++)
    arrival[i]=0; burst[i]=0; w[i]=0; g[i]=0;


printf("# of processes: ");
scanf("%d",&n);

//Input
for(i=0;i<n;i++)
  {
    printf("Enter arrival time, burst time for process P%d : ",i+1);
    scanf("%d",&arrival[i]);
    scanf("%d",&burst[i]);
  }

g[0]=0;
for(i=0;i<10;i++)
    g[i+1]=g[i]+burst[i];

//Execute jobs in order of arrival
for(i=0;i<n;i++)
{
    w[i]=g[i]-arrival[i];
    t[i]=g[i+1]-arrival[i];
    avg_wt=avg_wt+w[i];
    avg_ta=avg_ta+t[i];
}

avg_wt =avg_wt/n;
avg_ta=avg_ta/n;
printf("\n\tPID\tWait Time\tTA Time\n");

for(i=0;i<n;i++)
    printf("\tP%d\t\t%d\t\t%d\n",i,w[i],t[i]);

printf("AVG Wait Time : %.2f\n",avg_wt);
printf("AVG TA Time : %.2f\n",avg_ta);


}

//Priiority Scheduling for jobs

void priority_scheduling()
{
  int i,j,n,time,sum_wait=0,sum_turnaround=0;
  int smallest,arrival[10],burst[10],priority[10],remain;

  printf("# of Processes : ");
  scanf("%d",&n);
  remain=n;

  for(i=0;i<n;i++)
  {
      printf("Enter arrival time, burst time and priority for process P%d : ",i+1);
      scanf("%d",&arrival[i]);
      scanf("%d",&burst[i]);
      scanf("%d",&priority[i]);
  }

  priority[9]=11;
  printf("\n\tPID\tWait Time\tWait Time\n");

  for(time=0;remain!=0;)
  {
    smallest=9;
    for(i=0;i<n;i++)
    {
        //Look for the highest priority process remaining
        if(arrival[i]<=time && priority[i]<priority[smallest] && burst[i]>0)
        {
            smallest=i;
        }
    }

    //Execute highest priority process remaining
    
    time+=burst[smallest];
    remain--;

    printf("\tP%d\t\t%d\t\t%d\n",smallest+1,time-arrival[smallest],time-arrival[smallest]-burst[smallest]);

    sum_wait+=time-arrival[smallest]-burst[smallest];
    sum_turnaround+=time-arrival[smallest];
    burst[smallest]=0;

  }
  printf("\nAVG Wait Time : %.2f\n",sum_wait*1.0/n);
  printf("AVG TA Time : %.2f",sum_turnaround*1.0/n);

}


//Shortest job first
void Shortest_job_First_sort()
{
	int i,j,n,k,t,e=0,m=0;
  float aw,at,sum1;

  printf("\n\n# of processes : ");
  scanf("%d",&n);

  int p[n],a[n],b[n],w[n],ta[n],t1;


  for(i=0;i<n;i++)
    {
      printf("Enter process no., arrival time, burst time : ");
      scanf("%d%d%d",&p[i],&a[i],&b[i]);
    }


  //Sort according to burst time in increasing order
   for(i=0;i<n;i++)
    {
     for(j=i+1;j<n;j++)
      {
       if((a[i]>a[j]) || ((a[i]==a[j]) && (b[i]>b[j])))
          {
           t=a[i];
           a[i]=a[j];
           a[j]=t;

           t=b[i];
           b[i]=b[j];
           b[j]=t;

           t=p[i];
           p[i]=p[j];
           p[j]=t;
          }
      }
    }


k=a[0]+b[0];
for(i=1;i<n;i++)
    {
     for(j=i+1;j<n;j++)
      {

       if(b[i]>b[j] && k>=a[j])
          {
             m=1;

             t=b[i];
             b[i]=b[j];
             b[j]=t;

             t=a[i];
             a[i]=a[j];
             a[j]=t;

             t=p[i];
             p[i]=p[j];
             p[j]=t;
          }
      }

      if (m==0)
       k=k+b[i];
      else
       k++;
      m=0;
   }

//Execute according to sorted sequence
t1=0;
 for(i=0;i<n;i++)
  {
  if (t1-a[i]<0)
    {
     t1+=a[i]-t1;
    }
   if(i==0)
    w[i]=0;
   else
    w[i]=t1-a[i];
    t1+=b[i];
  }

 for(i=0;i<n;i++)
   ta[i]=b[i]+w[i];

printf("\n\tPID\tWait Time\tWait Time\n");
  for(i=0;i<n;i++)
  {
        printf("\tP%d\t\t%d\t\t%d\n",p[i],w[i],ta[i]);
  }


 printf("\nAVG Wait Time : ");

 sum1=0.0;
  for(i=0;i<n;i++)
   {
    sum1+=w[i];
   }

 aw=sum1/n;
 printf("%.2f",aw);

 printf("\nAverage TA Time : "); 

 sum1=0.0;
  for(i=0;i<n;i++)
   {
    sum1+=ta[i];
   }

 at=sum1/n;
 printf("%.2f",at);

}



//Round Robin
void round_robin()
{

	int i,j,n,time,remain,flag=0,ts;
  int sum_wait=0,sum_turnaround=0,at[10],bt[10],rt[10];

  printf("# of Processes : ");
  scanf("%d",&n);

  remain=n;
  for(i=0;i<n;i++)
  {
    printf("Enter arrival time and burst time for process P%d :",i+1);
    scanf("%d",&at[i]);
    scanf("%d",&bt[i]);
    rt[i]=bt[i];
  }

  printf("Enter time slice : ");
  scanf("%d",&ts);


  printf("\n\tPID\tTA Time\tWait Time\n\n");

  //Repeat until no processes remain
  for(time=0,i=0;remain!=0;)
  {
    if(rt[i]<=ts && rt[i]>0)
    {
      //Process can be completed within time slice
      time+=rt[i];
      rt[i]=0;
      flag=1; 
    }
    else if(rt[i]>0)
    {
      //Execute time slice
      rt[i]-=ts; 
      time+=ts;
    }

    if(rt[i]==0 && flag==1)
    //Process completed
    {
      remain--;
      printf("\tP%d\t\t%d\t\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
      sum_wait+=time-at[i]-bt[i];
      sum_turnaround+=time-at[i];
      flag=0;
    }

    if(i==n-1)
      i=0;
    else if(at[i+1]<=time)
      i++;
    else
      i=0;
  }

  printf("\nAVG Wait Time : %f\n",sum_wait*1.0/n);
  printf("AVG TA Time : %f",sum_turnaround*1.0/n);

}


//Shortest remaining time
void Shortest_remaining_time_first()
{
   int at[10],bt[10],rt[10],endTime,i,smallest;
    int remain=0,n,time,sum_wait=0,sum_turnaround=0;


    printf("# of Processes : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter arrival and burst time for Process P%d : ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }


    printf("\n\tPID\tTA Time\tWait Time\n\n");

    rt[9]=9999;
    for(time=0;remain!=n;time++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            //Find process with least remaining time
            if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0)
            {
                smallest=i;
            }
        }
        rt[smallest]--;
        if(rt[smallest]==0)
        {
            //Complete process with least remaining time
            remain++;
            endTime=time+1;
            printf("\tP%d\t\t%d\t\t%d",smallest+1,endTime-at[smallest],endTime-bt[smallest]-at[smallest]);
            sum_wait+=endTime-bt[smallest]-at[smallest];
            sum_turnaround+=endTime-at[smallest];
        }
    }
    printf("\n\nAVG Wait Time : %f\n",sum_wait*1.0/n);
    printf("AVG TA Time : %f",sum_turnaround*1.0/5);
}
