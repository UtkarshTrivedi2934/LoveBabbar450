//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
       int f(int i, int j, string &pattern, string &text,
      vector<vector<int>> &dp){
      if(i < 0 && j < 0)return true;
     if(i <0 && j >= 0)return false;
     if(j<0 && i>=0){
      for(int ii = 0;ii<=i;ii++){
         if(pattern[ii] != '*') return false;
      }
      return true;
   }
     if(dp[i][j] != -1) return dp[i][j];
     if(pattern[i] == text[j] || pattern[i] == '?'){
      return dp[i][j] = f(i-1, j-1, pattern, text, dp);
   }
     if(pattern[i] == '*') {
      return dp[i][j] = f(i-1, j, pattern, text, dp)
           | f(i, j-1, pattern, text, dp);
   }
    return dp[i][j] = false;
}
    
    bool match(string pattern, string text)
    {
        // code here
        int n = pattern.size();
        int m = text.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, pattern, text, dp);
    }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends