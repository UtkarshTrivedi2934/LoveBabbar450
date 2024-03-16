//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solve(int coins[],int ind,int n,int T,vector<vector<long long>> &output) {
        // base case
        if(T == 0)
        return 1;
        
        if(ind == n) {
            return 0;
        }
        
        if(output[ind][T]!=-1)
        return output[ind][T];
        
        // recursive call
        long long Take = 0;
        long long notTake = solve(coins,ind+1,n,T,output);
        if(coins[ind] <= T) {
            Take = solve(coins,ind,n,T-coins[ind],output);
        }
        return output[ind][T] = Take + notTake;
    }
  
    long long int count(int coins[], int n, int sum) {
        vector<vector<long long>> output(n+1,vector<long long>(sum+1,-1)); 
        return solve(coins,0,n,sum,output);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends