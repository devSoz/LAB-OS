#include <iostream>

using namespace std;

int main() {
	int n = 5, m = 3;
    int loan[5][4] = { { 0, 0, 1, 2}, { 1, 0, 0, 0}, { 1, 3, 5, 4}, { 0, 6, 3, 2}, { 0, 0, 1, 4} };
    int max[5][4] = { { 0, 0, 1, 2}, { 1, 7, 5, 0}, { 2, 3, 5, 6}, { 0, 6, 5, 2}, { 0, 6, 5, 6} }; 
    int avail[4] = { 1, 5, 2, 0 }; 

    int f[n], ans[n], ind = 0;
    for (int k = 0; k < n; k++)
	    f[k] = 0;

    int need[n][m];
    for (int i = 0; i < n; i++) 
	    for (int j = 0; j < m; j++)
	        need[i][j] = max[i][j] - loan[i][j];

    int y = 0;
    for (int k = 0; k < 5; k++) 
	    for (int i = 0; i < n; i++) 
	        if (f[i] == 0) {
                int flag = 0;
		        for (int j = 0; j < m; j++) 
		        if (need[i][j] > avail[j]) {
			        flag = 1;
			        break;
		        }
		    

		        if (flag == 0) {
		            ans[ind++] = i;
		            for (y = 0; y < m; y++)
			            avail[y] += loan[i][y];
		            f[i] = 1;
		        }
	        }
	


    int flag = 1;

    for (int i = 0; i < n; i++)
		if(f[i]==0) {
		    flag = 0;
		    cout << "The given sequence is not safe";
		    break;
	    }


    if(flag==1) {
	    cout << "Following is the SAFE Sequence" << endl;
	    for (int i = 0; i < n - 1; i++)
		    cout << " P" << ans[i] << " ->";
	    cout << " P" << ans[n - 1] <<endl;
    }

	return 0;
}
