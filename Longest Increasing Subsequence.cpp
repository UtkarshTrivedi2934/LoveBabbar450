//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
   int longestSubsequence(int n, int a[]) {
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int index=lower_bound(res.begin(), res.end(), a[i])-res.begin();
            if(index==res.size()) {
                res.push_back(a[i]);
            } 
            else {
                res[index]=a[i];
            }
        }
        return res.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends