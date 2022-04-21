#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;
  
int pageFaults(int pages[], int n, int capacity) {
    unordered_set<int> s;
    queue<int> indexes;
    int pageFaults = 0;

    for(int i=0; i<n; i++) {
        if(s.size() < capacity)
            if(s.find(pages[i]) == s.end()) {
                s.insert(pages[i]);
                pageFaults++;
                indexes.push(pages[i]);
            }
  
        else
            if(s.find(pages[i]) == s.end()) {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                pageFaults++;
            }
    }
  
    return pageFaults;
}
  
int main() {
    int pages[] = {4, 7, 2, 0, 1, 3, 2, 3, 4, 2, 1, 5, 7, 6, 2, 6, 3, 2, 1, 2, 3, 6};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 4;

    cout<<"Number of Page Faults: "<<pageFaults(pages, n, capacity);

    return 0;
}