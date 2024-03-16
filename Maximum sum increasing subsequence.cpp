//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int solve(int arr[], int n, int ind, int prev, vector<vector<int>> &dp) {
	    if(ind >= n)
	    return 0;
	    
	    if(dp[ind][prev+1]!=-1)
	    return dp[ind][prev+1];
	    int take = 0;
	    if(arr[ind] > arr[prev] or prev == -1) 
	    take = arr[ind] + solve(arr,n,ind+1,ind,dp);
	    int notTake =  solve(arr,n,ind+1,prev,dp);
	    return dp[ind][prev+1] = max(take,notTake);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	    int ind = 0;
	    int prev = -1;
	    return solve(arr,n,ind, prev,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends