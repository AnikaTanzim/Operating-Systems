#include<iostream>
using namespace std;

int main()
{
    // Process id's

    int n ;
    cout << "enter the number of process: ";
    cin >> n;
    int processes[n];
    for(int i=1 ; i<=n;i++)
    {
        processes[i]=i;
    }
    // Burst time of all processes
    int burst_time[n];// = {5, 7, 9};
    cout<< "Enter the CPU times: ";
    for(int i=0 ; i<n;i++)
    {
        int b;
        cin >> b;
        burst_time[i]= b;
    }
    // Arrival time of all processes
    int arrival_time[n];// = {4, 0,2};
    cout<< "Enter the arrival times: ";
    for(int i=0 ; i<n;i++)
    {
        int b;
        cin >> b;
        arrival_time[i]= b;
    }
    //findavgTime(processes, n, burst_time, arrival_time);
    int wt[n];

    wt[0]=0;
             cout << wt[0];
   // sort(arrival_time)
    for(int i =1; i<n;i++){
         wt[i] = burst_time[i-1] + wt[i-1] -arrival_time[i];

         if (wt[i] < 0)
            wt[i] = 0;
            cout << wt[i];
    }
















    return 0;
}
