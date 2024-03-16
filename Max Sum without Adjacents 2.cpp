//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  
    int solve(vector<int> &a, int n, int ind, int count, vector<vector<int>> &dp) {
        if(ind>=n)
        return 0;
        
        if(dp[ind][count]!=-1)
        return dp[ind][count];
        
        int take = 0;
        if(count<2)
        take = a[ind] + solve(a, n, ind+1, count+1, dp);
        int notTake = solve(a, n, ind+1, 0, dp);
        return dp[ind][count] = max(take, notTake);
    }
  
    int findMaxSum(vector<int>& a){
      //Code Here
      vector<vector<int>> dp(a.size(), vector<int>(3, -1));
      return solve(a, a.size(), 0, 0, dp);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends