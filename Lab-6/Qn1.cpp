#include <iostream>
using namespace std;

void CalculateTurnaround(int a[], int b[], int tmp[], int n, int quantum)
{
    int total = 0, flag = 0, cnt = n, waittime = 0, turnaround = 0;
    cout << "\n Process# \t Burst Time \t Arrival Time \t Turnaround Time \t Waiting Time ";
    for (int i = 0; cnt != 0;)
    {
        if (tmp[i] <= quantum && tmp[i] > 0)
        {
            total += +tmp[i];
            tmp[i] = 0;
            flag = 1;
        }
        else if (tmp[i] > 0)
        {
            tmp[i] -= quantum;
            total += quantum;
        }
        if (tmp[i] == 0 && flag == 1)
        {
            cnt--;
            cout << "\n    " << i + 1 << "\t\t    " << b[i] << "\t\t\t" << a[i];
            cout << "\t\t " << total - a[i] << "\t\t " << total - a[i] - b[i];
            waittime += total - a[i] - b[i];
            turnaround += total - a[i];
            flag = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (a[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    cout << "\n Average Turn Around Time: " << waittime * 1.0 / n;
    cout << "\n Average Waiting Time    : " << turnaround * 1.0 / n;
    cout << "\n Total Idle Time         : " << total;
}

int main()
{
    int n, quantum;
    cout << "Enter number of process: ";
    cin >> n;
    cout << "Enter the Time Quantum for the process: ";
    cin >> quantum;

    int a[n], b[n], tmp[n];
    float avg_wt, avg_tat;

    cout << "Enter the Burst and Arrival time of the Process:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i] >> a[i];
        tmp[i] = b[i];
    }

    CalculateTurnaround(a, b, tmp, n, quantum);
    return 0;
}