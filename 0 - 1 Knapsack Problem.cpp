//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int KnapSack(int n,int *weight,int *value,int maxweight,int **output) {
    //Base case
    if(n == 0 or maxweight == 0)
    return 0;

    int ans;
    // 2.Check if answer exists
    if(output[n][maxweight] != -1)
    return output[n][maxweight];

    //Recursion
    if(weight[0] > maxweight) {
        output[n][maxweight] = KnapSack(n-1,weight+1,value + 1,maxweight,output);
        return KnapSack(n-1,weight+1,value + 1,maxweight,output);
    }
    

    else {
        int x = KnapSack(n-1,weight+1,value+1,maxweight - weight[0],output) + value[0];
        int y = KnapSack(n-1,weight+1,value+1,maxweight,output);
        ans = max(x,y);
    }
    // 3. Save answer
    output[n][maxweight] = ans;
    return ans;

}

    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int **output = new int*[n+1];
    // 1.Create output array
    for(int i = 0;i<=n;i++) {
        output[i] = new int[W+1];
            for(int j = 0;j<=W;j++)  {
                output[i][j] = -1;
            }
    }
    return KnapSack(n,wt,val,W,output);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends