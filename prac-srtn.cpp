
#include<iostream>>
#include<stdio.h>
using namespace std;

struct process{
    int art;
    int cput;
    int wt;
    int tat;
    int pid;
    int ft;
    int x;


};

int main()

{
    int n, time=0 ,smallest,c=0;
    double avgt=0,avgwt=0,endd;

    cout << "enter the number of process: ";
    cin >> n;

    struct process p[n+1];

    for(int i=0; i<n;i++)
    {
        p[i].pid = i+1;

    }

    // Arrival time of all processes
    cout<< "Enter the arrival times: ";
    for(int i=0 ; i<n;i++)
    {
        int b;
        cin >> b;
        p[i].art = b;
    }

    // cpu time of all processes
    cout<< "Enter the CPU times: ";
    for(int i=0 ; i<n;i++)
    {
        int b;
        cin >> b;
        p[i].cput=b;
        p[i].x = p[i].cput;
    }

    p[n].cput= 99999;
    for(int time=0;c!=n;time++){
        smallest=n;
        for(int i =0;i<n;i++){
            if(p[i].art<=time && p[i].cput<p[smallest].cput && p[i].cput>0){
                smallest = i;
                cout <<"----p"<< p[smallest].pid<<"----"<<time+1;
            }


        }
        p[smallest].cput--;
        //if(i==smallest)
//cout <<"----p"<< p[smallest].pid<<"----"<<time+1;
        if(p[smallest].cput == 0){
            c++;
            endd=time+1;
            p[smallest].ft=endd;
            p[smallest].wt = endd - p[smallest].art-p[smallest].x;
            p[smallest].tat = endd - p[smallest].art;
        }
    }


    return 0;
}
