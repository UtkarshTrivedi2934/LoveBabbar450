//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int mod = 1e9+7;
    int Maximize(int a[],int n)
    {
        sort(a,a+n);
        unsigned long long int ans = 0;
        for(int i=0;i<n;i++)
            ans = (ans + ((unsigned long long)a[i]*i)%mod )%mod;
        return ans;
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends