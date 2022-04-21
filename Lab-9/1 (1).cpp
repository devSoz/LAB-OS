#include <bits/stdc++.h>
using namespace std;

int bankers(int allocation[][3], int demand[][3], int avail[3], int nP, int nR)
{
	int f[nP], ans[nP], ind = 0;  //f-stores the status of a process
    for (int i = 0; i < nP; i++)
        f[i] = 0;   
    
    int need[nP][nR];     //need- stores the need for each process (remaining resources required)
                          //need = max demand - allocation
    for (int i = 0; i < nP; i++)
        for (int j = 0; j < nR; j++)
            need[i][j] = demand[i][j] - allocation[i][j];
    
    int y = 0;
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < nP; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < nR; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < nR; y++)
                        avail[y] += allocation[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;
    //If all the processes has been exectuted with the alloted resources, then it's safe 
    //(ie, f[i]=1 for all the processes)
    for (int i = 0; i < nP; i++)
        if (f[i] == 0)
        {
            flag = 0;
            cout << "Not a safe sequence!";
            break;
        }

    if (flag == 1)
    {
        cout << "A safe sequence!!\n";
        for (int i = 0; i <= nP - 1; i++)
            cout << " P" << ans[i] << " ->";
    }

    return (0);
}

int main()
{
    int nP=5, nR=3;

    int allocation[][3] = {{0, 1, 0},   //Alloted resources to the processes
                           {2, 0, 0},  
                           {3, 0, 2},  
                           {2, 1, 1},  
                           {0, 0, 2}}; 

    int demand[5][3] = {{7, 5, 3},  //Maximum demand for each process
                        {3, 2, 2},  
                        {9, 0, 2},
                        {2, 2, 2},  
                        {4, 3, 3}};

    int avail[3] = {3, 3, 2};  //Availabe resources
	
	bankers(allocation, demand, avail, nP, nR);
}
