#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

void pageFaultsFIFO(int frame_size, int n, int pages[])
{
    int arr[N];
    queue<int> Q;
    int page_faults = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[pages[i]] != true)
        {
            Q.push(pages[i]);
            arr[pages[i]] = true;

            if (Q.size() > frame_size)
            {
                int p = Q.front();
                arr[p] = false;
                Q.pop();
            }
            page_faults++;
        }
    }
    cout << "No of Page faults: " << page_faults << "\n\n";
    return;
}
int main()
{
    int nFrame = 4;
    int pages[] = {4, 7, 2, 0, 1, 3, 2, 3, 4, 2, 1, 5, 7, 6, 2, 6, 3, 2, 1, 2, 3, 6};
    int n = 22;
    pageFaultsFIFO(nFrame, n, pages);
    return 0;
}
