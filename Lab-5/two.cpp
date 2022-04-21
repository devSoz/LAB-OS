#include <iostream>

using namespace std;

// Non-Preemptive Algorithm

struct process
{
    int pid, bt;
};

int main()
{
    process proc[] = {{1, 12}, {2, 22}, {3, 14}, {4, 7}, {5, 10}};
    int n = sizeof(proc) / sizeof(proc[0]);
    int wt[n], tat[n], total = 0, pos, temp;
    float avg_wt, avg_tat;

    for (int i = 0; i < n; i++)
    {
        pos = i;
        for (int j = i + 1; j < n; j++)
            if (proc[j].bt < proc[pos].bt)
                pos = j;

        temp = proc[i].bt;
        proc[i].bt = proc[pos].bt;
        proc[pos].bt = temp;

        temp = proc[i].pid;
        proc[i].pid = proc[pos].pid;
        proc[pos].pid = temp;
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = 0;

        for (int j = 0; j < i; j++)
            wt[i] += proc[j].bt;

        total += wt[i];
    }

    avg_wt = (float)total / n;
    total = 0;

    cout << "Processes "
         << " Waiting Time "
         << " Turn Around Time\n";
    for (int i = 0; i < n; i++)
    {
        tat[i] = proc[i].bt + wt[i];
        total += tat[i];

        cout << " " << proc[i].pid << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
    }

    avg_tat = (float)total / n;

    cout << "\nAverage waiting time = " << avg_wt;
    cout << "\nAverage turn around time = " << avg_tat;

    return 0;
}