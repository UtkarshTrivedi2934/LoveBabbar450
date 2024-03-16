//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> rearrange(vector <int> &a,int n)
        {
            //sorting the array in ascending order.
            sort(a.begin(),a.end());
            
            int i=0;
            
            //finding the index where the first non-1 element starts.
            while(i<n && a[i]==1)
                i++;
            
            //if there are two elements left after the first non-1 element
            //and those two elements are 2 and 3, then no need to rearrange further 
            //and we can return the array as it is.
            if(n-i==2 && a[i]==2 && a[i+1]==3)
                return a;
            
            //if all the elements are 1, then no need to rearrange further 
            //and we can return the array as it is.
            else if(i==n)
                return a;
            
            //reversing the elements from index i until the end of the array.
            reverse(a.begin()+i,a.end());
            
            //returning the rearranged array.
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector<int> ans=s.rearrange(a,n);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends