#include <iostream>
#include <algorithm>

using namespace std;
 
struct process {
    int id;
    int burstTime;
    int priority;
    int waitingTime;
    int turnAroundTime;
    int finishingTime;
};
 
bool operator<(process p1, process p2)
{
    if(p1.priority < p2.priority)
        return true;

    return false;
}
 
void ganttChart(process *p, int n) {
    cout<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<p[i].burstTime; j++) 
            cout<<"--";
        cout<<" ";
    }
    cout<<"\n|";

  
    for(int i=0; i<n; i++) {
        for(int j=0; j<p[i].burstTime - 1; j++)
            cout<<" ";
        cout<<p[i].id;
        for(int j=0; j<p[i].burstTime - 1; j++)
            cout<<" ";
        cout<<"|";
    }
    cout<<endl;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<p[i].burstTime; j++)
            cout<<"--";
        cout<<" ";
    }
    cout<<endl;

    cout<<"0";
    for(int i=0; i<n; i++) {
        for(int j=0; j<p[i].burstTime; j++) 
            cout<<"  ";
        if(p[i].turnAroundTime > 9)
            cout<<'\b';
        cout<<p[i].turnAroundTime;
    }
    cout<<endl;

    return;
}
 
void priorityScheduling(process *p, int n) {
    sort(p, p+n);
    float totalWaitingTime = 0, totalTurnAroundTime = 0;
 
    for(int i=0; i<n; i++) {
        if(i != 0)
            p[i].finishingTime = p[i-1].finishingTime + p[i].burstTime;
        else
            p[i].finishingTime = p[i].burstTime;
        p[i].turnAroundTime = p[i].finishingTime;
        p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
 
        totalWaitingTime += p[i].waitingTime;
        totalTurnAroundTime += p[i].turnAroundTime;
    }

    cout<<"\n#P\t"<<"FT\t"<<"WT\t"<<"TAT\n\n";

    for(int i = 0; i < n; i++) 
        cout<<p[i].id<<"\t"<<p[i].finishingTime<<"\t"<<p[i].waitingTime<<"\t"<<p[i].turnAroundTime<<endl;

    cout<<"Average Waiting Time: "<<(totalWaitingTime/n)<<"\n";
    cout<<"Average Turn Around Time: "<<(totalTurnAroundTime/n)<<"\n";

    ganttChart(p, n);

    return;
}
 
int main()
{
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    
    process *p = new process[n];
    for(int i=0; i<n; i++) {
        p[i].id = i + 1;
        cout<<"Enter burst time for process "<<i+1<<": ";
        cin>>p[i].burstTime;
        cout<<"Enter priority for process "<<i+1<<": ";
        cin>>p[i].priority;
    }
 
    priorityScheduling(p, n);
 
    return 0;
}