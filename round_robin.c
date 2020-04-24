#include<stdio.h>
int main()
{
	int count,j,n,time=0,remain,flag=0,time_quantum;
	int bt[10],rt[10];

	printf("Enter the number of total processes:\n");
	scanf("%d",&n);
  	remain=n;

  	for(count=0;count<n;count++)
  	{
    		printf("Enter Burst Time for Process Number %d :",count+1);
    		scanf("%d",&bt[count]);
    		rt[count]=bt[count];
  	}

	printf("Enter Time Quantum:\t");
  	scanf("%d",&time_quantum);


 	printf("\n\nProcess Name\t|Remaining Time\t|\ttotal Time\n\n");


  	for(time=0,count=0;remain!=0;)
  	{

    	if(rt[count]<=time_quantum && rt[count]>0)
    	{
      		time+=rt[count];
     		rt[count]=0;
      		flag=1;
            printf("%d\t\t\t  %d\t\t\t  %d\t\t\t\n",count+1,rt[count],time);
        }
        else if(rt[count]>0)
    	{
		//printf("a");
      		rt[count]-=time_quantum;
      		time+=time_quantum;
            printf("%d\t\t\t  %d\t\t\t  %d\t\t\t\n",count+1,rt[count],time);
    	}

        if(rt[count]==0 && flag==1)
    	{
      		remain--;
      		flag=0;
    	}

        if(count==n-1)
            count=0;
        else
            count++;
  }


 }


