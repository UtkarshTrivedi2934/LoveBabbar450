//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int arr[]){
        vector<pair<int,int>> v;
        for(int i = 0;i<n;i++) {
            v.push_back({arr[i],i+1});
        }
        
        sort(v.begin(),v.end());
        int count= 0;
        for(auto i:v) {
            if(k >= i.first*i.second) {
                count+= i.second;
                k-= i.first*i.second;
            }
            else {
                count+= k/i.first;
                k-= i.first*(k/i.first);
            }
            
        }
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends