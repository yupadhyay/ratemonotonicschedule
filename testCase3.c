#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<errno.h>
#include<sys/time.h>
#include<time.h>


#define SCHED_RT_PERIODIC 6
#define loop 1000

int main()
{

struct sched_param *sp;
int P=0,C,T;

//sp->sched_priority=19;
int error;
T=35;
C=5;
sp=(struct sched_param *)malloc(sizeof(struct sched_param));
sp->sched_priority=C<<16;
sp->sched_priority=sp->sched_priority|T;
error=sched_setscheduler( getpid(),6, sp);
printf("error = %d pid =  %d\n",error,getpid());

  int i=0,t;
 long j=0,k;
 struct timeval tv1,tv2,tv3,tv4;
 unsigned long startTime,endTime,totalTime,totalTime1,res1=0;
 int time_taken,runs=0;
 int x=0;
 int flag=0;
 unsigned long computeTime;
if(error<0)
{
 printf("\nCould not admit the process\n");
 return 0;
}
gettimeofday(&tv3,NULL);
	totalTime=tv3.tv_sec*1000000 + tv3.tv_usec;
	
while(1)
{
	gettimeofday(&tv1,NULL);
	startTime=tv1.tv_sec*1000000 + tv1.tv_usec;
	
	{
	for(k=0;k<loop;k++)
	{
		for(j=0;j<loop;j++)
		{
			x=(99999+299999)/10000;
		}
	}
	gettimeofday(&tv2,NULL);
		endTime= tv2.tv_sec*1000000 + tv2.tv_usec;
		computeTime = (endTime-startTime)/1000;
		runs++;		
		
	}
		if(computeTime>T)
		{
		 printf("\nTime taken:%d\n",computeTime);
		 printf("\nYou missed my deadline\n");
		 
		}
		
	
		
		while(computeTime<T)
		{
			sched_yield();
			if(flag==0)
			printf("Process yielding C is %d and T is %d \n",computeTime,T);
			flag=1;
			gettimeofday(&tv2,NULL);
			endTime= tv2.tv_sec*1000000 + tv2.tv_usec;
			computeTime = endTime-startTime;
		}
		flag=0;
		gettimeofday(&tv4,NULL);
		totalTime1= tv4.tv_sec*1000000 + tv4.tv_usec;
		res1 = (totalTime1-totalTime)/1000;
			
}
return 0;

}
