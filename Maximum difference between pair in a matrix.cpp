//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findMaxValue(vector<vector<int>>& A, int N) {
    int R = INT_MIN, x;
    for (int i = 1; i < N; i++)
        A[0][i]=min(A[0][i],A[0][i-1]),
        A[i][0]=min(A[i][0],A[i-1][0]);
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            x=A[i][j],
            A[i][j]=min(x,min(A[i-1][j],A[i][j-1])),
            R=max(R,x-A[i-1][j-1]);
    return R;
}
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>mat(n,vector<int>(n, 0));
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            cin >> mat[i][j];
	        }
	    }
	    Solution ob;
	    int ans = ob.findMaxValue(mat, n);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends