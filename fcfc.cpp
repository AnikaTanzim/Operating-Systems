#include<bits/stdc++.h>
using namespace std;

struct ar{
int index, att, cpt;
};

bool cmp(ar x, ar y)
{
    if(x.att<y.att)
        return true;
    return false;
}

int main()
{
    int n, wt[100],tt[100],t=0;
    double avgt=0,avgwt=0;
    ar art[100];
    printf("enter the number of process");
    scanf("%d",&n);
    printf("enter the arival time");
    for(int i =0;i<n;i++)
    {
      //  art[i].att=i;
        scanf("%d",&art[i].att);
        art[i].index=i+1;
    }
    printf("enter the cpu time");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&art[i].cpt);
    }

    sort(art,art+n,cmp);
    for(int i=0;i<n;i++)
    {
        wt[i]=t-art[i].att;
        tt[i]=wt[i]+art[i].cpt;
        t=t+art[i].cpt;
    }

     printf("Process\tWaiting Time\tTurn Around Time\n");

    for(int i=0;i<n;i++)
   {
     printf("P %d\t %d\t\t\t %d\n",art[i].index,wt[i],tt[i]);
   }
   for(int i=0;i<n;i++)
   {
        avgwt+=wt[i];
        avgt+=tt[i];
   }
   avgwt=avgwt/n;
   avgt=avgt/n;
   printf("the avg wt = %lf and the avg tt =%lf",avgwt,avgt);
    return 0;
}
