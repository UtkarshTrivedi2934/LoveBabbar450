//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int getMaxCuts(int n,int x,int y,int z,vector<int> &dp){
        if(n < 0){
            return -1;
        }
        
        if(n == 0){
            return 0;
        }
        
        if(dp[n] != INT_MIN){
            return dp[n];
        }
        
        int op1 = getMaxCuts(n-x,x,y,z,dp);
        int op2 = getMaxCuts(n-y,x,y,z,dp);
        int op3 = getMaxCuts(n-z,x,y,z,dp);
        
        if(op1 == -1 && op2 == -1 && op3 == -1){
            return dp[n] =  -1;
        }
        
        dp[n] = max(op1,max(op2,op3))+1;
        return dp[n];
    }
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,INT_MIN);
        int ans = getMaxCuts(n,x,y,z,dp);
        //when no segments can be cut then we should return 0
        if(ans == -1){
            ans = 0;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends   