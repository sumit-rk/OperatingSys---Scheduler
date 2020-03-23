#include<iostream.h>

struct Processes
{
  int p_id = 0;
  int burst_time = 0;
}

int main()
{
  int n,i,ari_time;
  printf("\n Enter the total number of processes : ");
  scanf("%d",&n);

  Processes procs[n];
  printf("\n Enter the details of the processes : ");
  for(int i=0; i<n; i++)
  {
     printf("\n Details of P-%d",i+1);
     printf("\n Arrival time of the P-%d",i+1);
     scanf("%d",ari_time);
     procs[i].p_id = i+1;
     procs[i].burst_time = 2*ari_time;
  }

  for(int i=0; i<n; i++)
  {
     printf("\n Process ID of P-%d is %d."i+1,procs[i].p_id);
     printf("\n Burst time of P-%d is %d.",i+1,procs[i].burst_time);
  }

  return 0;
}
