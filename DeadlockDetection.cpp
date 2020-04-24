#include<bits/stdc++.h>
using namespace std;
# define WHITE 0
# define GRAY 1
# define BLACK 2

vector<int> ar[100];
vector<int> CyclePath;
int color[100]={0};
int parent[100];
int cycleFound=0;
void dfs(int u)
{
    color[u]= GRAY;
    for(int i=0;i<ar[u].size();i++)
    {
        int v=ar[u][i];
        if(color[v]==GRAY)
        {
            cycleFound=1;
            int temp = u;
            CyclePath.push_back(v);
            while(temp!=v)
            {
                CyclePath.push_back(temp);
                temp=parent[temp];
            }
        }
        if(color[v]==WHITE)
        {
            parent[v]=u;
            dfs(v);
        }
    }
    color[u]=BLACK;
}
int main(){
    int n,m;
    printf("enter the number of nodes ");
    scanf("%d",&n);
    printf("enter the number of edges ");
    scanf("%d",&m);
    printf("enter the edge connections");
    for(int i =0 ;i<m;i++)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        ar[x].push_back(y);
    }
    for(int i=0;i<n;i++)
    {
        if(color[i]==WHITE)
        {
            dfs(i);
        }

    }
    if(cycleFound==1)
    {
        for (int i =0;i<CyclePath.size();i++)
        {
            printf("%d\t",CyclePath[i]);
        }
    }
    else printf("no cycle found");
    return 0;
}
