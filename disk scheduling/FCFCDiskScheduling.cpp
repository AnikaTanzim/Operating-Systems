#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, TotalMov=0,head,req[100];

    printf("enter the number of requests");
    scanf("%d",&n);

    printf("enter the requests :");
    for(int i =0;i<n;i++){
        scanf("%d",&req[i]);
    }

    printf("\nenter the head :");
    scanf("%d",&head);

    printf("cyclinder serving order : %d",head);

    for(int i =0;i<n;i++)
    {
        TotalMov+=abs(head-req[i]);
        head=req[i];
        printf("-> %d",req[i]);
    }

    printf("\ntotal serving : %d",TotalMov);

    return 0;
}
