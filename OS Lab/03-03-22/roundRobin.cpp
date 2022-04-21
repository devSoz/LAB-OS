#include <iostream>
#include <algorithm> 
#include <queue> 
#include <cstring>

using namespace std;

struct process {
    int pid;
    int arrivalTime;
    int burstTime;
    int turnaroundTime;
    int waitingTime;

    int startTime;
    int completionTime;
};

bool compare1(process p1, process p2) { 
    return p1.arrivalTime < p2.arrivalTime;
}

bool compare2(process p1, process p2) {  
    return p1.pid < p2.pid;
}

int main() {
    int n, tq;
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter time quantum: ";
    cin>>tq;

    process *p = new process[n];
    int *burstRemaining = new int[n];
    int totalTurnaroundTime = 0, totalWaitingTime = 0, totalIdleTime = 0;;
    float avgTurnaroundTime, avgWaitingTime;
    int idx;

    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrivalTime;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burstTime;
        burstRemaining[i] = p[i].burstTime;
        p[i].pid = i+1;
        cout<<endl;
    }

    sort(p, p+n, compare1);

    queue<int> q;
    int currentTime = 0;
    q.push(0);
    int completed = 0;
    int *mark = new int[n];
    memset(mark, 0, sizeof(mark));
    mark[0] = 1;

    while(completed != n) {
        idx = q.front();
        q.pop();

        if(burstRemaining[idx] == p[idx].burstTime) {
            p[idx].startTime = max(currentTime, p[idx].arrivalTime);
            totalIdleTime += p[idx].startTime - currentTime;
            currentTime = p[idx].startTime;
        }

        if(burstRemaining[idx]-tq > 0) {
            burstRemaining[idx] -= tq;
            currentTime += tq;
        }

        else {
            currentTime += burstRemaining[idx];
            burstRemaining[idx] = 0;
            completed++;

            p[idx].completionTime = currentTime;
            p[idx].turnaroundTime = p[idx].completionTime - p[idx].arrivalTime;
            p[idx].waitingTime = p[idx].turnaroundTime - p[idx].burstTime;

            totalTurnaroundTime += p[idx].turnaroundTime;
            totalWaitingTime += p[idx].waitingTime;
        }

        for(int i = 1; i < n; i++) {
            if(burstRemaining[i] > 0 && p[i].arrivalTime <= currentTime && mark[i] == 0) {
                q.push(i);
                mark[i] = 1;
            }
        }
        if(burstRemaining[idx] > 0) {
            q.push(idx);
        }

        if(q.empty()) {
            for(int i = 1; i < n; i++) {
                if(burstRemaining[i] > 0) {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }


    }

    avgTurnaroundTime = (float) totalTurnaroundTime / n;
    avgWaitingTime = (float) totalWaitingTime / n;

    sort(p, p+n, compare2);

    cout<<"\n#P\t"<<"AT\t"<<"BT\t"<<"TAT\t"<<"WT\n\n";
    for(int i = 0; i < n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].arrivalTime<<"\t"<<p[i].burstTime<<"\t"<<p[i].turnaroundTime<<"\t"<<p[i].waitingTime<<"\t"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avgTurnaroundTime<<endl;
    cout<<"Average Waiting Time = "<<avgWaitingTime<<endl;

    return 0;
}