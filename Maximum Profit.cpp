//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dp[501][201][2];
    int solve(int A[], int n, int k, int curr, int trans) {
        if(!k or curr >= n)
        return 0;
        
        if(dp[curr][k][trans] != -1)
        return dp[curr][k][trans];
        
        if(trans) {
            return dp[curr][k][trans] = max(A[curr] + solve(A, n, k-1, curr+1, 0), solve(A, n, k, curr+1, trans));
        }
        else {
            return dp[curr][k][trans] = max(-A[curr] + solve(A, n, k, curr+1, 1), solve(A, n, k, curr+1, trans));
        }
    }
  
    int maxProfit(int K, int N, int A[]) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(A, N, K, 0, 0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends