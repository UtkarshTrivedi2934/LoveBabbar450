//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        long long mx = *max_element(arr,arr+n);
        
        if(mx < 0)
        return mx;
        
        long long max_soFar = INT_MIN;
        long long curr_max = 0;
        for(int i = 0;i<n;i++) {
            curr_max += arr[i];
            
            if(max_soFar < curr_max)
            max_soFar = curr_max;
            
            if(curr_max < 0)
            curr_max = 0;
        }
        return max_soFar;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends