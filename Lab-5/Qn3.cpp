#include <bits/stdc++.h>
using namespace std;
int arr[10][5];

void arrivalTimeSort(int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j][2] > arr[j + 1][2])
                for (k = 0; k <= 2; k++)
                    swap(arr[j][k], arr[j + 1][k]);
}

void calculate(int n)
{
    int startTime[n], finishTime[n];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            startTime[i] = arr[i][2];
        else
            startTime[i] = finishTime[i - 1];
        arr[i][3] = startTime[i] - arr[i][2];
        finishTime[i] = startTime[i] + arr[i][1];
        arr[i][4] = finishTime[i] - arr[i][2];
    }
}

void print_gantt_chart(int n)
{
    int i, j;
    cout << " ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
            cout << "--";
        cout << " ";
    }
    cout << "\n|";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1] - 1; j++)
            cout << " ";
        printf("P%d", arr[i][0]);
        for (j = 0; j < arr[i][1] - 1; j++)
            cout << " ";
        cout << "|";
    }
    printf("\n ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
            printf("--");
        printf(" ");
    }
    printf("\n");

    printf("0");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
            printf("  ");
        if (arr[i][4] > 9)
            printf("\b");
        printf("%d", arr[i][4]);
    }
    printf("\n");
}

int main()
{
    int i, j, n;
    float waitTimeAvg = 0, turnAroundTimeAvg = 0;
    cout << "Enter number of process: ";
    cin >> n;
    cout << "Enter burst time: \n";
    for (int i = 0; i < n; i++)
    {
        arr[i][0] = i + 1;
        cout << "Process P" << (i + 1) << ":   ";
        cin >> arr[i][1] >> arr[i][2];
        arr[i][3] = arr[i][4] = 0;
    }
    arrivalTimeSort(n);
    calculate(n);

    for (i = 1; i < n; i++)
    {
        arr[i][3] = arr[i - 1][3] + arr[i - 1][1];
        arr[i][4] = arr[i][3] + arr[i][1];
    }

    for (int i = 0; i < n; i++)
    {
        waitTimeAvg += arr[i][3];
        turnAroundTimeAvg += arr[i][4];
    }
    cout << "\n\nProcess\t\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
        cout << "P" << arr[i][0] << "\t\t" << arr[i][1] << "\t\t" << arr[i][2] << "\t\t" << arr[i][3] << "\t\t" << arr[i][4] << "\n";

    cout << "Average Waiting Time: " << (waitTimeAvg / n) << "\n";
    cout << "Average TurnAround Time: " << (turnAroundTimeAvg / n) << "\n\n";

    puts("          GANTT CHART          ");
    print_gantt_chart(n);
    return 0;
}
