//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int i,int j,int arr[],int N, vector<vector<int>> &output) {
        if(i>=j)
        return 0;
        int ans = INT_MAX;
        
        if(output[i][j] != -1)
        return output[i][j];
        
        for(int k = i;k<j;k++) {
            int tempCost = solve(i,k,arr,N,output) + solve(k+1,j,arr,N,output); 
            int extraCost = arr[i-1]*arr[k]*arr[j];
            int total = tempCost + extraCost;
            ans = min(total,ans);
        }
        return output[i][j] = ans;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i = 1;
        
        int j = N-1;
        vector<vector<int>> output(N+1,vector<int>(N,-1));
        return solve(i,j,arr,N,output);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends