//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    void solve(vector<int> &arr,int index,int sum,int l,int r,int &ans)
    {
        if(index==arr.size())
        {
            if(sum>=l && sum<=r)
                ans++;
            return;
        }
        solve(arr,index+1,sum,l,r,ans);
        solve(arr,index+1,sum+arr[index],l,r,ans);
    }
    
    long long int countSubsets(vector<int>&arr, int n, int l, int r){
        //Write your code here
        int ans=0;
        solve(arr,0,0,l,r,ans);
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    int l, r;
	    cin >> l >> r;
	    Solution ob;
	    long long int ans = ob.countSubsets(arr, n, l, r);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends