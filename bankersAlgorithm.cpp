#include<bits/stdc++.h>
using namespace std;
int resource;
int process;
int TotalResource[100];
int available[100];

int maxV[100][100];
int allocation[100][100];
int need[100][100];

bool visited[100];
vector<int> safeSeq;

int count1=0;

bool runProcess()
{
    int curr=-1;
    for(int i = 1;i<=process;i++)
    {
        bool check =true;
        if(visited[i]==true){
                continue;
            }
        for(int j =1;j<=resource;j++)
        {
            if(need[i][j]>available[j])
            {
              check=false;
            }

        }
        if(check)
        {
            curr = i;
              visited[i] = true;

            safeSeq.push_back(i);
            for (int r = 1; r <= resource; r++)
            {
                available[r] += allocation[curr][r];
            }
      return true;
        }
    }
    return false;
}
int main()
{
  printf( "Enter the number of process: ");
  scanf("%d",&process);
  printf( "Enter the number of resources: ");
  scanf("%d",&resource);

  for(int i =1;i<=process;i++)
  {
      for(int j=1;j<=resource;j++)
      {
          printf("\n");
          printf("max for P%d resource %d:",i,j);
          scanf("%d",&maxV[i][j]);
      }
          printf("\n");

      for(int j=1;j<=resource;j++)
      {
          printf("\n");
          printf("max for P%d allocation %d:",i,j);
          scanf("%d",&allocation[i][j]);
      }
  }
    printf("enter the total amount of resource : ");
  for(int i =1;i<=resource;i++)
  {
    scanf("%d",&TotalResource[i]) ;
  }
  for(int i=1;i<=resource;i++)
  {
      int sum=0;
     for(int j=1;j<=process;j++)
     {
        sum +=allocation[j][i];

     }
       available[i]=TotalResource[i]-sum;
  }
 printf("Available: ");
    for(int i=1;i<=resource;i++)
    {
        printf("%d  ",available[i] );
    }
  printf("\nNeed Matrix: ");
  for(int i =1;i<=process;i++)
  {
     for(int j=1;j<=resource;j++){
        need[i][j]=maxV[i][j] - allocation[i][j];
         printf("%d " ,need[i][j]);
     }
   printf("\n");
  }
  while(count1<process)
  {
    if(runProcess())
    {
      count1++;
    }
    else
    {
        printf( "The system is not it safe state");
        return 0;
    }
  }
  printf( "The system is in safe state");
  for(int i =0;i<safeSeq.size();i++)
  {
   printf("P%d ",safeSeq[i]);
  }
   return 0;
}
