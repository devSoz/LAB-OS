#include <bits/stdc++.h>
using namespace std;

void bankers(int alloc[][100], int demand[][100], int avail[], int nP, int nR)
{
    bool status[nP];
    int res[nP], ind = 0;

    for (int i = 0; i < nP; i++)
        status[i] = 0;

    int need[nP][nR];
    for (int i = 0; i < nP; i++)
        for (int j = 0; j < nR; j++)
            need[i][j] = demand[i][j] - alloc[i][j];

    int y = 0;

    for (int k = 0; k < nP; k++)
    {
        for (int i = 0; i < nP; i++)
        {
            if (status[i] == false)
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
                    res[ind++] = i;
                    status[i] = true;
                    for (int j = 0; j < nR; j++)
                        avail[j] += alloc[i][j];
                }
            }
        }
    }

    int flag = 1;
    //If all the processes has been exectuted with the alloted resources, then it's safe
    //(ie, f[i]=1 for all the processes)
    for (int i = 0; i < nP; i++)
        if (status[i] == false)
        {
            flag = 0;
            cout << "Not a safe sequence!";
            break;
        }

    if (flag == 1)
    {
        cout << "A safe sequence!!\n";
        for (int i = 0; i < nP; i++)
            cout << " P" << res[i] << " ->";
    }
}

int main()
{
    int nP, nR;
    cin >> nP >> nR;
    int allocation[nP][nR], demand[nP][nR], avail[nR];

    for (int i = 0; i < nP; i++)
        for (int j = 0; j < nR; j++)
            cin >> allocation[i][j];

    for (int i = 0; i < nP; i++)
        for (int j = 0; j < nR; j++)
            cin >> demand[i][j];

    for (int i = 0; i < nR; i++)
        cin >> avail[i];

    bankers(allocation, demand, avail, nP, nR);
}