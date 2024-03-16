//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
       // code here
        int n = S.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        int start = 0;
        int end = 0;
        
        if(n==1)
        return S;
        
        for(int i = 0;i<n;i++) {
            for(int j = i;j>=0;j--) {
                // len 1
                if(i==j)
                    dp[i][j] = 1;
                // len 2
                else if(i-j == 1) {
                    if(S[i] == S[j])
                        dp[i][j] = 1;
                }
                
                // len > 2
                else if(S[i] == S[j] and dp[i-1][j+1] == 1)
                    dp[i][j] = 1;
                
                if((dp[i][j] == 1) and (i-j > end-start))
            {
                    start = j;
                    end = i;
            }
            }
            
            
        }
        string ans = "";
        for(int i = start;i<=end;i++)
        ans.push_back(S[i]);
        return ans;
        // return S.substr(start,end+1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends