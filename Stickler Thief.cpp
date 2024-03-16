//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    
    int solve(int arr[],int ind,int n,vector<int> &output) {
        if(ind>=n)
        return 0;
        if(n == 0)
        return 0;
        
        if(output[ind] != -1)
        return output[ind];
        
        int take = arr[ind] + solve(arr,ind+2,n,output);
        int notTake = 0 + solve(arr,ind+1,n,output);
        
        return output[ind] = max(take,notTake);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        vector<int> output(n+1,-1);
        return solve(arr,0,n,output);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends