#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int ProcessID;
    int BurstTime;
    int Priority;
};

bool sortProcesses(Process p1, Process p2) //Sort by priority
{
    return (p1.Priority > p2.Priority);
}

void priorityScheduling(Process process[], int n)
{
    sort(process, process + n, sortProcesses);

    int waittime[n], turnaroundtime[n], totalwait = 0, totalturnaround = 0;

    //Calculate wait time
    waittime[0] = 0;

    for (int i = 1; i < n; i++)
        waittime[i] = process[i - 1].BurstTime + waittime[i - 1];

    //Calculate Turn around time
    for (int i = 0; i < n; i++)
        turnaroundtime[i] = process[i].BurstTime + waittime[i];

    cout << "\nProcess  "
         << " Burst time  "
         << " Waiting time  "
         << " Turn around time\n";

    for (int i = 0; i < n; i++)
    {
        totalwait += waittime[i];
        totalturnaround += turnaroundtime[i];
        cout << "   " << process[i].ProcessID << "\t\t"
             << process[i].BurstTime << "\t    " << waittime[i]
             << "\t\t  " << turnaroundtime[i] << endl;
    }

    cout << "\nAverage waiting time = " << (float)totalwait / (float)n;
    cout << "\nAverage turn around time = " << (float)totalturnaround / (float)n;

    cout << "\nGantt Chart: \n";
    int cnt = 1, id = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < process[i].BurstTime; j++)
            cout << "P" << process[i].ProcessID << " ";
        if (i != n - 1)
            cout << " => ";
    }
}

int main()
{
    int n, b, p;
    cout << "Enter number of process: ";
    cin >> n;
    Process process[n];
    cout << "Enter Burst time and Priority: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> b >> p;
        process[i].ProcessID = i + 1;
        process[i].BurstTime = b;
        process[i].Priority = p;
    }

    priorityScheduling(process, n);
    return 0;
}