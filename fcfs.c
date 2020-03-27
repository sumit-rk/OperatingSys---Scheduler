#include<stdlib.h>
#include<stdio.h>

struct Processes
{
  int p_id;
  int burst_time;
};

int wait_time(int n,struct Processes p[],int *waiting_time)
{ int i;
  waiting_time[0] = 0;
  for(i=1; i<n; i++)
  {
    waiting_time[i] = p[i-1].burst_time + waiting_time[i-1];
  }
}

int turnaround_time(int n,struct Processes p[],int waiting_time[],int *ta_time)
{ int k;
  for (k=0; k<n; k++)
  {
    ta_time[k] = p[k].burst_time + waiting_time[k];
  }
}

int avg_time(int n,struct Processes p[])
{
  int waiting_time[n];
  int ta_time[n];
  int total_wtime =0;
  int total_ta_time =0;
  int j;

  wait_time(n,p,waiting_time);
  turnaround_time(n,p,waiting_time,ta_time);

  for(j=0; j<n; j++)
  {
    total_wtime = total_wtime + waiting_time[j];
    total_ta_time = total_ta_time + ta_time[j];
    printf("\n Process number          :%d",j+1);
    printf("\n Process burst time      :%d",p[j].burst_time);
    printf("\n Process waiting time    :%d",waiting_time[j]);
    printf("\n Process turnaround time :%d",ta_time[j]);
    printf("\n");
  }

  printf("\n Average Waiting time     : %d",total_wtime/n);
  printf("\n Average Turnaround time  : %d",total_ta_time/n);
}

int main()
{
  int n,i,ari_time;
  printf("\n Enter the total number of processes : ");
  scanf("%d",&n);

  struct Processes procs[n];
  printf("\n Enter the details of the processes : ");
  for(i=0; i<n; i++)
  {
     printf("\n Details of P-%d",i+1);
     printf("\n Arrival time of the P-%d",i+1);
     scanf("%d",&ari_time);
     procs[i].p_id = i+1;
     procs[i].burst_time = 2*ari_time;
  }

  avg_time(n,procs);

  /*for(i=0; i<n; i++)
  {
     printf("\n Process ID of P-%d is %d.",i+1,procs[i].p_id);
     printf("\n Burst time of P-%d is %d.",i+1,procs[i].burst_time);
  }*/

  return 0;
}
