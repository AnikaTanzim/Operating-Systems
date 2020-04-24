#include<bits/stdc++.h>
using namespace std;
int req[100];
int cd, rd,head,n,totalmov=0;
bool visited[100];
vector<int> seq;
bool findReq(){
    for(int i =0;i<n;i++)
    {
        if(visited[i]==true)
        {
            continue;
        }
        if(req[i]==head)
        {
            seq.push_back(req[i]);
            visited[i]=true;
            return true;
        }
    }
    return false;
}
int main()
{

    printf("enter the number of request : ");
    scanf("%d",&n);
    printf("enter the request: ");
     for(int i =0;i <n;i++)
    {
        scanf("%d",&req[i]);
    }
    int R,L=0;
    printf("enter the no of cylinder :");
    scanf("%d",&R);
    R--;
    printf("enter the head:");
    scanf("%d",&head);
    printf("enter the cd and rd:");
    scanf("%d%d",&cd,&rd);
    int cnt=0;
     printf("enter the cylinder sequence is : %d",head );
    while(cnt<n)
    {
        if(cd==rd)
        {
            if(findReq())
            {
                cnt++;
            }
        }
        if(cd==1)
        {
            head++;
        }
        else
            head--;
        if(head==R)
        {
            cd=0;
        }
        if(head==L)
        {
            cd=1;
        }
        totalmov++;
    }
    printf("enter the total movement is  : %d",totalmov );

    for(int i =0;i <seq.size();i++)
    {
        printf("-> %d",seq[i]);
    }
     return 0;

}
/*98 183 37 122 14 124 65 67
*/
