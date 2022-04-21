#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nP, nR;
    cout << "Enter the number of processes and resources: ";
    cin >> nP >> nR;
    int allocation[nP][nR], demand[nP][nR], avail[nR];
    int allocation[][3] = {{0, 1, 0},  // P0 // Allocation Matrix
                           {2, 0, 0},  // P1
                           {3, 0, 2},  // P2
                           {2, 1, 1},  // P3
                           {0, 0, 2}}; // P4

    int demand[5][3] = {{7, 5, 3},  // P0 // MAX Matrix
                        {3, 2, 2},  // P1
                        {9, 0, 2},  // P2
                        {2, 2, 2},  // P3
                        {4, 3, 3}}; // P4

    int avail[3] = {3, 3, 2}; // Available Resources

    int f[nP], ans[nP], ind = 0;
    for (int k = 0; k < nP; k++)
    {
        f[k] = 0;
    }
    int need[nP][nR];
    for (int i = 0; i < nP; i++)
    {
        for (int j = 0; j < nR; j++)
            need[i][j] = demand[i][j] - allocation[i][j];
    }
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

    // To check if sequence is safe or not
    for (int i = 0; i < nP; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            cout << "The given sequence is not safe";
            break;
        }
    }

    if (flag == 1)
    {
        cout << "Following is the SAFE Sequence" << endl;
        for (int i = 0; i < nP - 1; i++)
            cout << " P" << ans[i] << " ->";
        cout << " P" << ans[nP - 1] << endl;
    }

    return (0);
}