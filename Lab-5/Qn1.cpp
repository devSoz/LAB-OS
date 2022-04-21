#include <bits/stdc++.h>
using namespace std;
int arr[10][6];


void arrivalTimeSort(int arr[][6], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j][1] > arr[j + 1][1])
                for (k = 0; k < 2; k++)
                    swap(arr[j][k], arr[j + 1][k]);
}

void calculate(int n, int arr[][6])
{
    int temp, val;
    arr[0][3] = arr[0][0] + arr[0][1];
    arr[0][5] = arr[0][3] - arr[0][1];
    arr[0][4] = arr[0][5] - arr[0][0];

    for (int i = 1; i < n; i++)
    {
        temp = arr[i - 1][3];
        int min = arr[i][0];
        for (int j = i; j < n; j++)
        {
            if (temp >= arr[j][1] && min >= arr[j][0])
            {
                min = arr[j][0];
                val = j;
            }
        }
        arr[val][3] = temp + arr[val][0];
        arr[val][5] = arr[val][3] - arr[val][1];
        arr[val][4] = arr[val][5] - arr[val][0];
        for (int k = 0; k < 6; k++)
        {
            swap(arr[val][k], arr[i][k]);
        }
    }
}

int main()
{
    int n, temp;
    float waitTimeAvg = 0, turnAroundTimeAvg = 0;

    cout << "Enter number of Process: ";
    cin >> n;

    cout << "Enter burst time time and arrival time: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process P" << (i + 1) << ":   ";
        cin >> arr[i][0] >> arr[i][1];
    }

    /*cout << "Before Arrangment:\n";
    cout << "Process ID\tBurst Time\tArrival Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t\t" << arr[i][0] << "\t\t"
             << arr[i][1] << "\n";
    }*/

    arrivalTimeSort(arr, n);
    calculate(n, arr);

    cout << "\n\nProcess\t\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
        cout << "P" << i + 1 << "\t\t" << arr[i][0] << "\t\t" << arr[i][1] << "\t\t" << arr[i][4] << "\t\t" << arr[i][5] << "\n";

    for (int i = 0; i < n; i++)
    {
        waitTimeAvg += arr[i][4];
        turnAroundTimeAvg += arr[i][5];
    }
    cout << "Average Waiting Time: " << (waitTimeAvg / n) << "\n";
    cout << "Average TurnAround Time: " << (turnAroundTimeAvg / n) << "\n\n";
}
