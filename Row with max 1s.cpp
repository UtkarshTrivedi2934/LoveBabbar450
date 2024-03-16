//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // start from last col
	    int c = m-1;
	    // start from first row
	    int r = 0;
	    int max_row_index = -1;
	    // ladder traversal
	    while(c >= 0 and r < n) {
	        if(arr[r][c] == 1)
	        {
	            max_row_index = r;
	            // check for next col 
	            c--;
	        }
	        else
	        //move to next row
	        r++;
	    }
	    return max_row_index;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends