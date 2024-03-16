//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        
        int f(int h,int m,int prev,vector<vector<int>>& dp){
            if(h <= 0 || m <= 0) return 0;
            
            if(dp[h][m] != -1) return dp[h][m];
            
            int first=0,second=0,third=0;
            
            if(prev != 1) first = 1 + f(h+3,m+2,1,dp);
            if(prev != 2 and h > 5 and m > 10) second = 1 + f(h-5,m-10,2,dp);
            if(prev != 3 and h > 20) third = 1 + f(h-20,m+5,3,dp);
            
            return dp[h][m] = max({first,second,third});
        }
        int maxLevel(int h,int m)
        {
            // code here
            vector<vector<int>> dp(2007,vector<int>(2007,-1));
            int prev = 0;
            return f(h,m,prev,dp);
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    Solution a;
    while(t--)
    {
        int h,m;
        cin>>h>>m;
        cout<<a.maxLevel(h,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends