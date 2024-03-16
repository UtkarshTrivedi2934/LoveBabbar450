//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int kadane(vector<int> &ans) {
        int n = ans.size();
        int maxi = INT_MIN;
        int curr = 0;
        for(int i = 0;i<n;i++) {
            curr+=ans[i];
            maxi = max(curr,maxi);
            if(curr < 0)
            curr = 0;
        }
        return maxi;
    }
    
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        
        int maxi = INT_MIN;
        for(int i = 0;i<R;i++) {
            vector<int> ans(C);
            for(int j = i;j<R;j++) {
                for(int k = 0;k<C;k++) {
                    ans[k] += M[j][k];
                }
                maxi = max(maxi,kadane(ans));
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends