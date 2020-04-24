#include<iostream>
#include<stdio.h>
using namespace std;

struct process{
    int pid;
    int cput;
    int wt;
    int tat;
    int x;
    int ft;

};

int main(){

    int count,time=0,remain,flag=0,time_quantum;
    int n;
    double endd,avgt=0,avgwt=0;

    cout << "enter the number of process: ";
    cin >> n;
    remain = n;
    struct process p[n];

    for(int i=0; i<n;i++)
    {
        p[i].pid = i+1;

    }

    // cpu time of all processes
    cout<< "Enter the CPU times: ";
    for(int i=0 ; i<n;i++)
    {
        int b;
        cin >> b;
        p[i].cput=b;
        p[i].x = p[i].cput;

    }
    cout<< "Enter time quantam: ";
    cin >> time_quantum;

    count = 0;
    time = 0;

    printf("\n\nProcess Name\t|Remaining Time\t|\ttotal Time\n\n");

    while(remain!=0)
    {
       if(p[count].cput<=time_quantum && p[count].cput>0)
    	{
      		time+=p[count].cput;
     		p[count].cput=0;
      		flag=1;
            printf("%d\t\t\t  %d\t\t\t  %d\t\t\t\n",p[count].pid,p[count].cput,time);
        }
        else if(p[count].cput>0)
    	{
      		p[count].cput-=time_quantum;
      		time+=time_quantum;
            printf("%d\t\t\t  %d\t\t\t  %d\t\t\t\n",p[count].pid,p[count].cput,time);
    	}

    	if(p[count].cput==0 && flag==1)
    	{
      		remain--;
      		flag=0;

            endd=time;
            p[count].ft = endd;
            p[count].wt = endd - p[count].x ;
            p[count].tat = endd;
    	}

        if(count==n-1)
            count=0;
        else
            count++;
  }




    //print

    printf("pid \t burst \twaiting \tturnaround \tcompletion");
    for(int i=0;i<n;i++)
    {
        printf("\n %d \t   %d \t\t%d   \t\t%d\t\t%d",p[i].pid,p[i].x,p[i].wt,p[i].tat,p[i].ft);
        avgwt = avgwt + p[i].wt;
        avgt = avgt + p[i].tat;
    }
    //printf("\n  %If   %If",avg,tt);
    printf("\n\nAverage waiting time = %lf\n",avgwt/n);
    printf("Average Turnaround time = %lf",avgt/n);





    return 0;
}
