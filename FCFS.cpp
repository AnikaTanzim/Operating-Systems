
#include <iostream>
using namespace std;

int main()
{
    int temp,n;

    cout<<"Enter Process Number:"<<endl;
    cin>>n;
    float n_=n;

    int process_array[n][6];

    for(int i=0; i<n; i++)
    {

        process_array[i][0]=i;
        process_array[i][4]=0;
        process_array[i][5]=0;
        process_array[i][3]=0;




    }


    cout<<"Enter CPU Times:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>process_array[i][2];






    }
    cout<<"Enter the arrival times:"<<endl;
    for(int i=0; i<n; i++)
    {

        cin>>process_array[i][1];






    }





    int temp_wait=0;
    float sum_wait=0;
    float sum_ta=0;

    for(int i=0; i<n; i++)
    {

        int min_index=0;
        int temp_min=process_array[min_index][1];
        for(int j=0; j<n; j++)
        {

            if(temp_min>process_array[j][1] && process_array[j][5]==0)
            {
                min_index=j;

                temp_min=process_array[j][1];


            }
            cout<<endl;








        }
        process_array[min_index][3]=temp_wait;
        process_array[min_index][3]=process_array[min_index][3]-process_array[min_index][1];
        sum_wait+=process_array[min_index][3];
        temp_wait+=process_array[min_index][2];
        process_array[min_index][4]=temp_wait;
        process_array[min_index][4]=process_array[min_index][4]-process_array[min_index][1];
        sum_ta+=process_array[min_index][4];
        process_array[min_index][5]=1;
        process_array[min_index][1]=9999;

    }









    for(int i=0; i<n; i++)
    {


        cout<<"Process "<<i+1<<": waiting time :"<<process_array[i][3]<<" Turnaround time :"<<process_array[i][4]<<endl;



    }
    cout<<"Average Waiting time: "<<sum_wait/n_<<endl;
    cout<<"Average Turnaround time: "<<sum_ta/n_<<endl;


}
