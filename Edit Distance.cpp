//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int solve(string &s,string &t,int i,int j,int n,int m,vector<vector<int>> &dp) {
        if(i>=s.size())
        return t.size() - j;
        
        if(j>=t.size())
        return s.size() - i;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        if(s[i] == t[j]) {
            return solve(s,t,i+1,j+1,n,m,dp);
        }
        
        else{
            // inserting character means length of t string is same because 
            // we have inserted a character, right? but the length of s string is decreased
            // by one.
            int ins = 1+solve(s,t,i+1,j,n,m,dp);
            // deleting character means length of s string is same because 
            // we have deleted a character from t, right? so length of t is decreased by 1.
            int del = 1+solve(s,t,i,j+1,n,m,dp);
            // replace means unmatched character is replaced, so after replacing
            //  we have a character match.
            int rep = 1+solve(s,t,i+1,j+1,n,m,dp);
            return dp[i][j] = min(ins,min(del,rep));
        }
    }
  
    int editDistance(string s, string t) {
        // Code here
        
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s,t,0,0,n,m,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends