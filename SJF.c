#include<stdlib.h>
#include<stdio.h>

int procs[10][6];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arng_burst(int n,int procs[][6])
{
    int i,j,k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(procs[j][2] > procs[j+1][2])
            {
                for(k=0; k<5; k++)
                {
                    swap(&procs[j][k],&procs[j+1][k]);
                }
            }
        }
    }
}

int wait_time(int n,int procs[][6])
{ int i;
  procs[0][4] = 0;
  for(i=1; i<n; i++)
  {
    procs[i][4] = procs[i-1][2] + procs[i-1][4];
  }
}

int turnaround_time(int n,int procs[][6])
{ int k;
  for (k=0; k<n; k++)
  {
    procs[k][5] = procs[k][2] + procs[k][4];
  }
}

int avg_time(int n,int procs[][6])
{
  double total_wtime =0.0;
  double total_ta_time =0.0;
  int j;
  arng_burst(n,procs);
  wait_time(n,procs);
  turnaround_time(n,procs);

  for(j=0; j<n; j++)
  {
    total_wtime = total_wtime + procs[j][4];
    total_ta_time = total_ta_time + procs[j][5];
  }

  printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");

  for(j=0; j<n; j++)
  {
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",procs[j][0],procs[j][1],procs[j][2],procs[j][4],procs[j][5] );
  }
  printf("\n");
  printf("\nTotal Waiting time     : %lf",total_wtime);
  printf("\nTotal Turnaround time  : %lf",total_ta_time);
  printf("\n");
  printf("\nAverage Waiting time     : %lf",total_wtime/n);
  printf("\nAverage Turnaround time  : %lf",total_ta_time/n);
}

int main()
{
  int n,i,j,ari_time;
  printf("\n Enter the total number of processes : ");
  scanf("%d",&n);

  printf("\n Enter the details of the processes : ");
  for(i=0; i<n; i++)
  {
     printf("\n Details of P-%d....  ",i+1);
     printf("\n Arrival time of the P-%d.....  ",i+1);
     scanf("%d",&ari_time);
     procs[i][0] = i;
     procs[i][1] = ari_time;
     procs[i][2] = 2*ari_time;
  }
  printf("\nProcesses before Arranging : ");
  printf("\nProcess ID\tArrival Time\tBurst Time");
  for(j=0; j<n; j++)
  {
    printf("\n%d\t\t%d\t\t%d",procs[j][0],procs[j][1],procs[j][2]);
  }

  printf("\nProcesses after Arranging : ");
  arng_burst(n,procs);
  printf("\nProcess ID\tArrival Time\tBurst Time");
  for(j=0; j<n; j++)
  {
    printf("\n%d\t\t%d\t\t%d",procs[j][0],procs[j][1],procs[j][2]);
  }

  avg_time(n,procs);

  /*for(i=0; i<n; i++)
  {
     printf("\n Process ID of P-%d is %d.",i+1,procs[i].p_id);
     printf("\n Burst time of P-%d is %d.",i+1,procs[i].burst_time);
  }*/

  return 0;
}
