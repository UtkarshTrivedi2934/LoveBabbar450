//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    
    long long int mod = 1e9+7;
    
    long long int solve(string &str, int n, int i, int j, vector<vector<long long int>> &dp) {
        if(i==j)
        return 1;
        
        if(i>j)
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j]%mod;
        
        if(str[i] == str[j])
        return dp[i][j] = 1 + (solve(str, n, i+1,j, dp) + solve(str, n, i, j-1, dp))%mod; 
        else
        return dp[i][j] = (solve(str, n, i+1, j, dp) + solve(str, n, i, j-1, dp) - solve(str, n, i+1, j-1, dp) + mod)%mod;
    }
    
    long long int  countPS(string str)
    {
       //Your code here
       int n = str.size();
       vector<vector<long long int>> dp(n+1,vector<long long int>(n+1,-1));
       return solve(str, n, 0, n-1, dp);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends   