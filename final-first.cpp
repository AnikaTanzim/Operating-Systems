#include<bits/stdc++.h>
using namespace std;

int req[10000];

int main()
{
    int n;
    cout << "Enter the number of requests: ";
    cin >> n;
    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++)
    {
        cin >> req[i];
    }
    cout << "Enter the head position: ";
    int head;
    cin >> head;
    int total_movement = 0;
    cout << "Cylinder serving order: " << head;
    for (int i = 0; i < n; i++)
    {
        total_movement += abs(head - req[i]);
        head = req[i];
        cout << " -> " << req[i];
    }
    cout << "\n";
    cout << "Total Cylinder movement: " << total_movement << "\n";
    return 0;
}
/*
Enter the number of requests: 7
Enter the requests: 82
170
43
140
24
16
190

ans: 642

Enter the number of requests: 8
Enter the requests: 98
183
37
122
14
124
65
67

ans:640
*/
