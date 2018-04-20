#include<stdio.h> 
#include<stdlib.h>
int main() 
{ 
  int count,i,n,time,r,flag=0,tq; 
  int wt=0,tat=0,at[10],bt[10],rt[10]; 
  printf("Enter total number of process:"); 
  scanf("%d",&n); 
  r=n; 
  for(count=0;count<n;count++) 
  { 
    printf("enter the arrival time and burst time of the process %d :\n",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&tq); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;r!=0;) 
  { 
    if(rt[count]<=tq && rt[count]>0) 
    { 
      time=time+rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]=rt[count]-tq; 
      time=time+tq; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      r--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wt=wt+time-at[count]-bt[count]; 
      tat=tat+time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
    {
      count=0;
    }
    else if(at[count+1]<=time) 
     {
     	count++;
	 } 
    else 
    {
    	 count=0;
	} 
  } 
  printf("\nAverage Waiting Time= %f\n",wt*1.0/n); 
  printf("Avg Turnaround Time = %f",tat*1.0/n); 
  return 0; 
}

