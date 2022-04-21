#include <bits/stdc++.h>
using namespace std;

int pageFaultsLRU(int n, int nFrames, int pages[])
{
    int nPageFault = 0; //Page fault count
    vector<int> v;

    int i;
    for (i = 0; i <= n - 1; i++)
    {

        auto it = find(v.begin(), v.end(), pages[i]); //returning position of the element in the memory else returns end

        if (it == v.end()) //If the elemtn is not present
        {
            if (v.size() == nFrames) //Memory size is full - equal to no of frames
                v.erase(v.begin());  //First element is removed as it is least recently used

            v.push_back(pages[i]); //Appending the recently accessed back at the last of the vector

            nPageFault++; //As it is a page fault, the count is incremented
        }

        else //If the page is present in the memory
        {
            v.erase(it);           //Delete it from the vector
            v.push_back(pages[i]); //Add it at the last as it is the most recently used
        }
    }

    // Return total page faults
    cout << "No of page faults: " << nPageFault;
}

int main()
{

    int pages[] = {2, 3, 4, 2, 1, 5, 7, 6, 2, 6, 3, 2, 1, 2, 3, 6, 4, 7, 2, 2, 3, 3};
    int n = 22, nFrames = 4;

    pageFaultsLRU(n, nFrames, pages);
    return 0;
}