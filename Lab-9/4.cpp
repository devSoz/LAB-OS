#include <iostream>
#include <conio.h>
using namespace std;

void linkedFileAllocation(int pages[])
{
    int start, len;
    cout << "Enter the index of the starting block and its length: ";
    cin >> start >> len;
    
    int k = len;
    if (pages[start] == 0){
        for (int j = start; j < (start + k); j++){
            if (pages[j] == 0){
                pages[j] = 1;
                cout << j << "---->";
            }
            else {
                k++;
            }
        }
    }
    else
        cout <<"The block " << start << " is already allocated" << endl;
    return;
}

int main()
{
    int nPages; 
    cout<<"Enter the total number of pages: ";
    cin>>nPages;
    int pages[nPages], p, x;

    for (int i = 0; i < nPages; i++)  //Marking all the pages as not allocated (0) at the beginning
        pages[i] = 0;
        
    cout << "Number of pages already allocated: ";
    cin >> p;
    cout << "Index of the pages already allocated: ";
    for (int i = 0; i < p; i++){
        cin >> x;
        pages[x] = 1;  //Noting the previously alloted pages by marking it as 1
    }

    linkedFileAllocation(pages);
    getch();
    return 0;
}


