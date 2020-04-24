#include<iostream>
#include<algorithm>
using namespace std;
struct process{
    int pid;
    int art;
    int cput;
    int wt;
    int tat;
};

bool acompare(process x, process y)
{
    if(x.art<y.art)
        return true;
    return false;
}

int main()
{

    int n, t=0 ;
    double avgt=0,avgwt=0;

    cout << "enter the number of process: ";
    cin >> n;

    struct process p[n];

    for(int i=0; i<n;i++)
    {
        p[i].pid = i+1;
        cout << p[i].pid;
    }

    // cpu time of all processes
    cout<< "Enter the CPU times: ";
    for(int i=0 ; i<n;i++)
    {
        int b;
        cin >> b;
        p[i].cput=b;
    }

    // Arrival time of all processes
    cout<< "Enter the arrival times: ";
    for(int i=0 ; i<n;i++)
    {
        int b;
        cin >> b;
        p[i].art = b;
    }

    sort(p,p+n,acompare);

    for(int i =0; i<n;i++){

        p[i].wt = t - p[i].art;
        p[i].tat = p[i].wt + p[i].cput;
        t = t + p[i].cput;

    }

    for(int i=0;i<n;i++)
    {
        avgwt+=p[i].wt;
        avgt+=p[i].tat;
    }
   avgwt=avgwt/n;
   avgt=avgt/n;
 cout << "\n\n";
   for(int i = 0;i<n;i++){
    cout << "process:" << p[i].pid << "\t waiting time: "
    <<p[i].wt<< "\t turn around time: " <<p[i].tat<<"\n";
   }

    return 0;

}
