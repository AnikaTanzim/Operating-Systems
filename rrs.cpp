#include<bits/stdc++.h>
using namespace std;


#define RESOURCES 3
#define MX 10


int n,q;
int bt[MX];
int rt[MX];
int wt[MX];
int tat[MX];
bool check = true;
void inputt()
{
    freopen("rr.txt", "r", stdin);
    cin >> n >> q;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> bt[i];
        rt[i] = bt[i];
    }
}


void checkRemain()
{
    for(int i = 0 ; i < n ; i++)
    {
        if(rt[i]!=0) return;
    }
    check = false;
}


int main()
{
    inputt();
    int sum = 0;


//    for(int i = 0 ; i < n ; i++)
//    {
//        wt[i] = sm;
//        tat[i] = wt[i] + bt[i];
//        cout << sm << " P" << i+1 << " ";
//        sm += bt[i];
//    }


    int index = 0;
    int prevIndex = -1;


    while(check)
    {
        checkRemain();
        if(index >= n) index = 0;
        if(rt[index] >= q)
        {
            cout << sum << " P" << index+1 << " ";


            rt[index] -= q;


            if(index != prevIndex)
            {
                wt[index] = sum - wt[index];
                prevIndex = index;
            }
            sum += q;
            index++;
        }
        else if(rt[index] <= q && rt[index] > 0)
        {
            cout << sum << " P" << index+1 << " ";


            if(index != prevIndex)
            {
                wt[index] = sum - wt[index];
                prevIndex = index;
            }
            sum += rt[index];
            rt[index] = 0;
            index++;
        }
        else
        {
            index++;
        }




    }


    cout << sum << endl;
    cout << "WaitingTime\tTurnAroundTime" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << wt[i] << "\t" << tat[i] << endl;
    }




}
