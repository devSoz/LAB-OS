#include <iostream>

using namespace std;

struct process {
    int id, bt, at, wt, ft, tat;
};

void FCFS(process proc[], int n) {
    double total_wt = 0.0;
    double total_tat = 0.0;
    for(int i=0; i<n; i++) {
        proc[i].ft = proc[i-1].ft + proc[i].bt;
        proc[i].tat = proc[i].ft - proc[i].at;
        proc[i].wt = proc[i].tat - proc[i].bt;

        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }

    cout << "Processes " << "Execution Time " <<  " Waiting Time " << " Turn Around Time\n";
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
        cout << " " << proc[i].id << "\t\t " << proc[i].ft << "\t\t " << proc[i].wt << "\t\t " << proc[i].tat << endl;
    }
    cout << "\nAverage waiting time = " << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;


    return;
}

void ganttChart(process p[], int n) {
    cout<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<p[i].bt; j++) 
            cout<<"--";
        cout<<" ";
    }
    cout<<"\n|";

  
    for(int i=0; i<n; i++) {
        for(int j=0; j<p[i].bt - 1; j++)
            cout<<" ";
        cout<<p[i].id;
        for(int j=0; j<p[i].bt - 1; j++)
            cout<<" ";
        cout<<"|";
    }
    cout<<endl;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<p[i].bt; j++)
            cout<<"--";
        cout<<" ";
    }
    cout<<endl;

    cout<<"0";
    for(int i=0; i<n; i++) {
        for(int j=0; j<p[i].bt; j++) 
            cout<<"  ";
        if(p[i].tat > 9)
            cout<<'\b';
        cout<<p[i].tat;
    }
    cout<<endl;

    return;
}

int main()
{
    process proc[] = { { 1, 12, 0, 0, 0, 0 }, { 2, 25, 2, 0, 0, 0 }, { 3, 13, 1, 0, 0, 0 }, { 4, 7, 0, 0, 0, 0 }, { 5, 11, 5, 0, 0, 0 } };
    int n = sizeof(proc) / sizeof(proc[0]);

    FCFS(proc, n);
    ganttChart(proc, n);

    return 0;
}