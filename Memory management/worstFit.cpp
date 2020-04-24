#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,sum=0,memReq[100],block[100],allocation[100];
    printf("enter the number of memory request: ");
    scanf("%d",&m);
    printf("enter the memory request: ");
    for(int i =0;i<m;i++)
    {
        scanf("%d",&memReq[i]);
        allocation[i]=-1;
    }
    printf("enter the number of blocks: ");
    scanf("%d",&n);
    printf("enter the blocks: ");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&block[i]);
    }
    for(int i =0;i<m;i++)
    {
        int wrstInd=-1;
        for(int j =0;j<n;j++)
        {
            if(block[j]>=memReq[i])
            {
                if(wrstInd==-1)
                {
                    wrstInd=j;
                }
                else if (block[wrstInd]<block[j])
                {
                    wrstInd=j;
                }
            }
        }
        if(wrstInd!=-1)
        {
            allocation[i]=wrstInd;
            block[wrstInd]-=memReq[i];
        }
        printf("%d : " ,memReq[i]);
        if(allocation[i]!=-1)
        {
            for(int k=0;k<n;k++)
            {
                printf("%d ",block[k]);
            }
            printf("\n");

        }
        else {
            for(int k=0;k<n;k++)
            {
                sum+=block[k];
            }
             printf("Not Allocated  External Fragmentation: %d ",sum);
        }
    }
    return 0;
}
