#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int pageFaults(int pages[], int n, int capacity) {
	unordered_set<int> s;
    unordered_map<int, int> indexes;
    int pageFaults = 0;
	
    for(int i=0; i<n; i++) {   
        if(s.size() < capacity) {
			if(s.find(pages[i]) == s.end()) {
				s.insert(pages[i]);
                pageFaults++;
			}
            indexes[pages[i]] = i;
		}

		else {
			if (s.find(pages[i]) == s.end()) {
				int lru = INT_MAX, val;
				for(auto it=s.begin(); it!=s.end(); it++)
				    if(indexes[*it] < lru) {
						lru = indexes[*it];
						val = *it;
					}

				s.erase(val);
                s.insert(pages[i]);
                pageFaults++;
			}
            indexes[pages[i]] = i;
		}
	}

	return pageFaults;
}

int main() {
	int pages[] = {2, 3, 4, 2, 1, 5, 7, 6, 2, 6, 3, 2, 1, 2, 3, 6, 4, 7 ,2, 2, 3, 3};
	int n = sizeof(pages)/sizeof(pages[0]);
	int capacity = 4;

	cout<<"Number of Page Faults: "<<pageFaults(pages, n, capacity);

	return 0;
}
