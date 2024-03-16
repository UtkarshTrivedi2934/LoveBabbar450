//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
   bool solve(string& A, string& B, string& C, int i, int j, vector<vector<int>>& memo){
        // base case
        if(i==0 and j==0){
            return true;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        
        bool c1 = false;
        bool c2 = false;
        
        if(i != 0 and A[i-1] == C[i+j-1]){
            c1 = solve(A, B, C, i-1, j, memo);
        }
        if(j != 0 and B[j-1] == C[i+j-1]){
            c2 = solve(A, B, C, i, j-1, memo);
        }
        
        memo[i][j] = c1 or c2;
        return memo[i][j];
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int i=A.size();
        int j=B.size();
        vector<vector<int>> memo(i+1, vector<int>(j+1, -1));
        
        return solve(A, B, C, i, j, memo);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends