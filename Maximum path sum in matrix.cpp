//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int row,int col,int n,vector<vector<int>> &Matrix,vector<vector<int>> &output) {
        if(row>=n or row < 0 or col < 0 or col >= n)
        return 0;
        
        if(output[row][col]!= -1)
        return output[row][col];
        
        int down = Matrix[row][col] + solve(row+1,col+1,n,Matrix,output);
        int left = Matrix[row][col] + solve(row+1,col,n,Matrix,output);
        int dia = Matrix[row][col] + solve(row+1,col-1,n,Matrix,output);

        
        output[row][col] = max(max(down,left),dia);
        return output[row][col];
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int row = 0;
        vector<vector<int>> output(N,vector<int>(N,-1));
        int maxi = INT_MIN;
        for(int j = 0;j<N;j++)
        maxi = max(maxi,solve(row,j,N,Matrix,output));
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends