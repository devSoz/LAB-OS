#include <iostream>
#include <cstring>

using namespace std;

void firstFit(int blockSize[], int m, int processSize[], int n) {
	int allocation[n];

	memset(allocation, -1, sizeof(allocation));

	for(int i=0; i<n; i++) 
		for(int j=0; j<m; j++)
		    if(blockSize[j] >= processSize[i]) {
				allocation[i] = j;
                blockSize[j] -= processSize[i];

				break;
			}

	cout<<"\nFirst Fit Algorithm";
	cout<<"\nProcess No.\tProcess Size\tBlock no.\n";
	for(int i=0; i<n; i++) {
		cout<<' '<< i+1<<"\t\t"<<processSize[i]<<"\t\t";
		if(allocation[i] != -1)
			cout<<allocation[i] + 1;
		else
			cout<<"Not Allocated";
		cout<<endl;
	}

    return;
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];

    memset(allocation, -1, sizeof(allocation));

    for(int i=0; i<n; i++) {
        int bestIdx = -1;
        for(int j=0; j<m; j++)
        	if(blockSize[j] >= processSize[i]) {
				if(bestIdx == -1)
                    bestIdx = j;
                else if(blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
			}

        if(bestIdx != -1) {
            allocation[i] = bestIdx;
			blockSize[bestIdx] -= processSize[i];
        }
    }

	cout<<"\nBest Fit Algorithm";
    cout<<"\nProcess No.\tProcess Size\tBlock no.\n";
    for(int i=0; i<n; i++) {
        cout<<' '<<i+1<< "\t\t"<<processSize[i]<<"\t\t";
        if(allocation[i] != -1)
            cout<<allocation[i] + 1;
        else
            cout<<"Not Allocated";
        cout<<endl;
    }

	return;
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
 
    memset(allocation, -1, sizeof(allocation));
 
    for(int i=0; i<n; i++) {
        int wstIdx = -1;
        for(int j=0; j<m; j++)
        	if(blockSize[j] >= processSize[i]) {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (blockSize[wstIdx] < blockSize[j])
                    wstIdx = j;
            }
 
        if(wstIdx != -1) {
            allocation[i] = wstIdx;
 			blockSize[wstIdx] -= processSize[i];
        }
    }
 
	cout<<"\nWorst Fit Algorithm";
    cout<<"\nProcess No.\tProcess Size\tBlock no.\n";
    for(int i=0; i<n; i++) {
        cout<<' '<<i+1<<"\t\t"<<processSize[i]<<"\t\t";
        if(allocation[i] != -1)
            cout<<allocation[i] + 1;
        else
            cout<<"Not Allocated";
        cout<<endl;
    }

	return;
}

int main()
{
	int blockSize[] = {100, 450, 250, 300, 600};
	int processSize[] = {212, 317, 172, 426};
	int m = sizeof(blockSize) / sizeof(blockSize[0]);
	int n = sizeof(processSize) / sizeof(processSize[0]);

	firstFit(blockSize, m, processSize, n);
	bestFit(blockSize, m, processSize, n);
	worstFit(blockSize, m, processSize, n);

	return 0 ;
}
