//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Two pointer
        int sum = 0;
        int mi = n+1;
        int start = 0;
        int end = 0;
        
        while(end < n) {
            while(sum <= x and end < n) 
                sum+=arr[end++];
            while(sum > x and start < n) {
                if(end - start < mi)
                    mi = end - start;
            
                sum-=arr[start++];
        }
        }
        
        return mi>n?0:mi;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends