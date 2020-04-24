#include<bits/stdc++.h>
using namespace std;

bool visited[100];
int req[100];
int head,n;
int MinRequest()
{
    int cmp= 9498415123;
    int Min=-1;
    for(int i =0;i <n;i++)
    {
        if(visited[i]== true)
        {
            continue;
        }
        if(abs(head-req[i])<cmp)
        {
            cmp= abs(head-req[i]);
            Min=i;
        }

    }
    visited[Min]=true;
    return Min;
}
int main()
{
    int TotalMov=0;
    printf("enter the number of request : ");
    scanf("%d",&n);
    printf("enter the request: ");
     for(int i =0;i <n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("enter the head: ");
    scanf("%d",&head);
    printf("cyclinder serving order : %d",head);
     for(int i =0;i <n;i++)
    {
        int temp = MinRequest();
        TotalMov+= abs(head-req[i]);
        head= req[i];
        printf("-> %d",req[i]);

    }
     printf("total movement: %d",TotalMov);
    return 0;
}
