//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int n, int w, int val[], int wt[], int ind, vector<vector<int>> &dp) {
        if(ind >= n)
        return 0;
        
        if(ind  == n-1)
        return (w/wt[n-1])*val[n-1];
        
        if(w < 0)
        return 0;
        
        if(dp[ind][w]!=-1)
        return dp[ind][w];
        
        int take = INT_MIN;
        int notTake = 0;
        
        if(w>=wt[ind]) 
        take = val[ind] + solve(n, w-wt[ind], val, wt, ind, dp);
        notTake = solve(n, w, val, wt,ind+1, dp);
        
        return dp[ind][w] = max(take, notTake);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N+1, vector<int>(W+1,-1));
        return solve(N, W, val, wt, 0, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends