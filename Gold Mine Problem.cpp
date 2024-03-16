//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isSafe(int n, int m, int i, int j) {
        return (i<n and j<m and i>=0 and j>=0);
    }

    int solve(int n, int m, vector<vector<int>> &M, int i, int j, vector<vector<int>> &dp) {
        if(j == m-1)
        return M[i][j];
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        int a, b,c;
        a = b = c = 0;
        if(isSafe(n,m,i,j+1)) {
            a += M[i][j] + solve(n, m, M, i, j+1,dp);
        }
        
        if(isSafe(n,m,i+1,j+1)) {
            b += M[i][j] + solve(n, m, M,  i+1, j+1,dp);
        }
        
        if(isSafe(n,m,i-1,j+1)) {
            c += M[i][j] + solve(n, m, M,  i-1, j+1,dp);
        }
        return dp[i][j] = max(a,max(b,c));
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int ans=0;
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        for(int i=0;i<n;i++)
        {
            int a=solve(n,m,M,i,0, dp);
            ans=max(a,ans);
        }
        return  ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends