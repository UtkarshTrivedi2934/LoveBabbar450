//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
   	int mod=1000000007;
    #define ll long long

    ll memoization(int i,vector<ll>& memo)
    {
        //base case
        if(i==1 or i==2)
        return i;
        
        //memo check
        if(memo[i]!=-1)
        return memo[i];
        
        //recursive calls
        ll a=memoization(i-1,memo)%mod;
        ll b=((i-1)*(memoization(i-2,memo)%mod))%mod;
        
        return memo[i]=(a+b)%mod;
    }
    int countFriendsPairings(int n) 
    { 
        vector<ll> memo(n+1,-1); 
        return memoization(n,memo);
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
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends