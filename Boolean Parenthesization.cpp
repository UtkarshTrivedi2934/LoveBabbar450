//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int dp[201][201][2];
    int solve(int i, int j, string &s, bool isTrue) {
        if(i>j)
        return 0;
        
        if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
        
        if(i == j)
        {
            if(isTrue)
            return s[i] == 'T';
            else
            return s[i] == 'F';
        }
        
        int ans = 0;
        for(int k = i+1;k<j;k+=2) {
            int lt = solve(i, k-1,s,true);
            int rt = solve(k+1,j,s,true); 
            int lf = solve(i, k-1,s,false);
            int rf = solve(k+1, j,s,false);
            if(s[k] == '&') {
                if(isTrue==true)
                   ans=ans+lt*rt;
                else
                   ans=ans+lt*rf+lf*rt+lf*rf;
            }
            else if(s[k] == '|') {
                if(isTrue == true) {
                    ans=ans+lt*rf+lf*rt+lt*rt;
                }
                else {
                    ans=ans+lf*rf;
                }
            }
            else if(s[k] == '^') {
                if(isTrue == true) {
                    ans=ans+lt*rf+lf*rt;
                }
                else {
                    ans=ans+lf*rf+lt*rt;
                }
            }
        }
        return dp[i][j][isTrue] = ans%1003;
    }
    
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(0,N-1,S,true);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends