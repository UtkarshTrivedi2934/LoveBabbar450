//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	   int AlternatingaMaxLength(vector<int>&nums){
		    int up = 1, down = 1;
		    for(int i=1; i<nums.size(); i++) {
		        if(nums[i]>nums[i-1]) up = down+1;
		        else if(nums[i]<nums[i-1]) down = up+1; 
		    }
		    return max(down, up);
		}



};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends