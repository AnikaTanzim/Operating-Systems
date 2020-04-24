#include<bits/stdc++.h>
using namespace std;
struct ar{
int index,cpt,att;
};
bool cmp(ar x,ar y)
{
    if(x.cpt<y.cpt)
    {
        return true;
    }
    else return false;
}
int main()
{
    int wt[100],tt[100],timer=0,n,total=0;
    double avgWT=0,avgTT=0;
    ar art[100];

    printf("enter the number of process\n");
    scanf("%d",&n);

    printf("enter the cpu time\n");
    for(int i =0;i<n;i++)
    {
        art[i].att=i;
        art[i].index=i+1;
        scanf("%d",&art[i].cpt);
    }

    sort(art,art+n,cmp);
    wt[0]=0;
    for(int i=1;i<n;i++)
    {

        wt[i]=wt[i-1]+art[i-1].cpt;
    }
    for(int i=0;i<n;i++)
    {

        tt[i]=wt[i]+art[i].cpt;


    }
    printf("Process\tWaiting Time\tTurn Around Time\n");
    for(int i=0;i<n;i++)
   {

     printf("P %d\t %d\t\t\%d\n",art[i].index,wt[i],tt[i]);
   }
    for(int i=0;i<n;i++)
   {
        avgWT+=wt[i];
        avgTT+=tt[i];
   }

   avgWT=avgWT/n;
   avgTT=avgTT/n;
   printf("the avg wt = %lf and the avg tt =%lf",avgWT,avgTT);
    return 0;
}
