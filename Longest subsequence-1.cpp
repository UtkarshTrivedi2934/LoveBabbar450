//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int arr[] ,int n, int ind, int prev, vector<vector<int>> &dp) {
        if(ind >= n)
        return 0;
        
        if(dp[ind][prev+1] != -1)
        return dp[ind][prev+1];
        
        int take = 0;
        if((abs(arr[prev] - arr[ind]) == 1) or prev==-1)
        take = 1+solve(arr, n, ind+1,ind, dp);
        int notTake = solve(arr, n, ind+1, prev, dp);
        return dp[ind][prev+1] = max(take, notTake);
    }

    int longestSubsequence(int N, int A[])
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(N+1, -1));
        return solve(A, N, 0, -1, dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends