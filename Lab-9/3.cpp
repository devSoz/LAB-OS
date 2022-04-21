#include <bits/stdc++.h>
using namespace std;

int pageToBeReplaced(int pages[], vector<int> &frame, int nPages, int index)
{
    int res = -1, farthest = index;
    
    for (int i = 0; i < frame.size(); i++)
    {
        int j;
        for (j = index; j < nPages; j++)
        {
            if (frame[i] == pages[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        
        if (j == nPages)  //If a page in the frame is not present in the future, it is returned
            return i;
    }

    //If no page in the frame is present in the future, the first one is replaced
    if(res==-1)
        return 0;
    else
        return res;
}

void optimalPageReplacement(int pages[], int nPages, int fn)
{
    vector<int> frames;  //To store the pages in the frame

    int nHits = 0;
    for (int i = 0; i < nPages; i++)
    {
        cout<<pages[i]<<": ";
        
        //Checking if the page already exists in the frame
        int flag = 0;
        for (int j = 0; j < frames.size(); j++)
            if (frames[j] == pages[i])
                flag = 1;
                
        if (flag==1)  //Page is found in the frame
        {
            cout<<"Hit";
            nHits++;
        }

        else
        {
            cout<<"Miss";
            if (frames.size() < fn)    //If there is an empty space in frame
                frames.push_back(pages[i]);

            else   //If frame is full, find the page to be replaced - not used in longest dimension in the future
            {
                int j = pageToBeReplaced(pages, frames, nPages, i + 1);
                cout<<" "<<frames[j];
                frames[j] = pages[i];
            }
        }
        cout<<"\n";
    }
    cout << "Hits = " << nHits << endl;
    cout << "Misses = " << nPages - nHits << endl;
}

int main()
{
    int pages[] = {3, 2, 1, 2, 3, 6, 4, 7, 2, 3, 4, 2, 1, 5, 7, 6, 2, 6, 2, 2, 3, 3};
    int nPages = 22, nFrames = 3;
    optimalPageReplacement(pages, nPages, nFrames);
    return 0;
}

