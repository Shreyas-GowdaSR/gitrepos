#include<stdio.h>
int main()
{
int bt[20],wt[20],tat[20],i,n;
float wtavg,tatavg;
clrscr();
printf("\n Enter the number of process--");
scanf("%d",&n);
for(i=0;i<n;i++)
{
  printf("\n Enter the Burst time for pracess %d--",i);
  scanf("%d",&bt[i]);
}
wt[0]=wtavg=0;
tat[0]=tatavg=bt[0];
for(i=1;i<n;i+)
{
   wt[i]=wt[i-1]+bt[i-1];
   tat[i]=tat[i-1]+bt[i];
   wtavg=wtavg+wt[i];
   tatavg=tatavg+tat[i];
}
printf("\t PROCESS \tBURST TIME \tWAITING TIME \tTURNAROUND TIME\n");
for(i=0;i<n;i++)
  printf("\n\t P%d\t\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tat[i]);
printf("\n Average waiting time--%f",wtavg/n);
printf("\n Average Turnaround time--%f",tatavg/n);
getch();
return 0;
}
