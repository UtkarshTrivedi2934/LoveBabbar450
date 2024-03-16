//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        long long prod = 1;
        long long z = 0;
        long long neg = 0;
        int max_neg = -11;
        long long mod = 1e9+7;
        
        if(n == 1)
        return a[0];
        
        for(auto i:a) {
            if(i<0) {
                neg++;
                max_neg = max(i,max_neg);
            }
            if(i)
            prod= (prod*i)%mod;
            else
            z++;
        }
        
        if((neg == 1 and z == n-1) or z == n)
        return 0;
        return neg%2?(prod/max_neg)%mod:prod%mod;
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
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends