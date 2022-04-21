#include <bits/stdc++.h>
using namespace std;
int arr[10][4];

void burstTimeSort(int n)
{
    for (int i = 0; i < n; i++)
    {
        int tempMin = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j][1] < arr[tempMin][1])
                tempMin = j;

        swap(arr[tempMin][1], arr[i][1]);
        swap(arr[tempMin][0], arr[i][0]);
    }
}

void calculate(int n)
{
    float waitTimeAvg, turnAroundTimeAvg;
    arr[0][2] = 0;

    for (int i = 1; i < n; i++)
    {
        arr[i][2] = 0;
        for (int j = 0; j < i; j++)
            arr[i][2] += arr[j][1];
        arr[i][3] = arr[i][2] + arr[i][1];
    }
}

int main()
{
    int n, temp;
    float waitTimeAvg = 0, turnAroundTimeAvg = 0;

    cout << "Enter number of Process: ";
    cin >> n;

    cout << "Enter burst time: \n";
    for (int i = 0; i < n; i++)
    {
        arr[i][0] = i + 1;
        cout << "Process P" << (i + 1) << ":   ";
        cin >> arr[i][1];
    }

    burstTimeSort(n);
    calculate(n);

    cout << "\n\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
        cout << "P" << arr[i][0] << "\t\t" << arr[i][1] << "\t\t" << arr[i][2] << "\t\t" << arr[i][3] << "\n";

    for (int i = 0; i < n; i++)
    {
        waitTimeAvg += arr[i][2];
        turnAroundTimeAvg += arr[i][3];
    }
    cout << "Average Waiting Time: " << (waitTimeAvg / n) << "\n";
    cout << "Average TurnAround Time: " << (turnAroundTimeAvg / n) << "\n\n";
}
