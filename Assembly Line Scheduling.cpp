//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


class Solution{
  public:
  int solve(int t, int pos, vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& x, vector<vector<int>>& dp){
      if(pos == a[0].size() - 1){
          return x[t]+a[t][pos];
      }
      if(dp[t][pos] != -1){
          return dp[t][pos];
      }
      
      int direct = solve(t, pos + 1, a, T, x, dp);
      int diag   = solve((1-t), pos + 1, a, T, x, dp) + T[t][pos+1];
      int tcost  = dp[t][pos] =  min(direct, diag) + a[t][pos];
      return tcost;
  }
 
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      int n = a[0].size();
      vector<vector<int>> dp(2, vector<int>(n+1, -1));

      int t0 = e[0] + solve(0, 0, a, T, x, dp);
      int t1 = e[1] + solve(1, 0, a, T, x, dp);
      return min(t0, t1);
  }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends