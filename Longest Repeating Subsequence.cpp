//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	    int solve(string &s,string &t,int n,int i,int j,vector<vector<int>> &dp) {
	        if(i>=n or j>=n)
	        return 0;
	        
	        if(dp[i][j] != -1)
	        return dp[i][j]; 
	        
	        if(s[i] == t[j] and i!=j) {
	            return 1+solve(s,t,n,i+1,j+1,dp);
	        }
	        
	        else {
	            return dp[i][j] = max(solve(s,t,n,i,j+1,dp),solve(s,t,n,i+1,j,dp));
	        }
	    }
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.length();
		    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
		    return solve(str,str,n,0,0,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends