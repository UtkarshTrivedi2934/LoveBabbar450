//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    int solve(vector<int> &nums, int i, int filled, int n, int k, vector<vector<int>> &dp) {
        if(i >= n)
        return 0;
        
        if(dp[i][filled] != -1)
        return dp[i][filled];
        
        if(filled!=0) {
            int take = INT_MAX;
            int notTake = 0;
            if(1+filled+nums[i] <= k) {
                take = solve(nums, i+1, 1+filled+nums[i], n, k, dp);
            }
            int rem = k - filled;
            notTake = rem*rem + solve(nums, i, 0, n, k, dp);
            return dp[i][filled] = min(take, notTake);
        }
        else {
            return dp[i][filled] = solve(nums, i+1, nums[i], n, k, dp);
        }
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(nums, 0, 0, n, k, dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends