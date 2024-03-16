//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int solve(int n, int x, int y,vector<int> &dp) {
	    if(n <= 1)
	    return n;
	    
	    int a = 1,b =1,c = 1;
	    
	    if(dp[n] != -1)
	    return dp[n];
	    
	    if(n-x>=0)
	    a = solve(n-x,x,y,dp);
	    
	    if(n-y>=0)
	    b = solve(n-y,x,y,dp);
	    
	    if(n-1>=0)
	    c = solve(n-1,x,y,dp);
	    
	    if(a == 0 or b == 0 or c == 0)
	    return dp[n] = 1;
	    return dp[n] = 0;
	}
	
	int findWinner(int N, int X, int Y)
	{
		// Your code goes here
		vector<int> dp(N+1, -1);
		
		return solve(N,X,Y,dp);
	}

};
	

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends