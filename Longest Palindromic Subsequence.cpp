//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int LPS(string &s,string &t,int n,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=n or j>=n)
	        return 0;
	        
	        if(dp[i][j] != -1)
	        return dp[i][j]; 
	        
	        if(s[i] == t[j]) {
	            return 1+LPS(s,t,n,i+1,j+1,dp);
	        }
	        
	        else {
	            return dp[i][j] = max(LPS(s,t,n,i,j+1,dp),LPS(s,t,n,i+1,j,dp));
	        }
    }
  
    int longestPalinSubseq(string A) {
        //code here
        string B = A;
        int n = A.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        reverse(A.begin(),A.end());
        return LPS(A,B,n,0,0,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends