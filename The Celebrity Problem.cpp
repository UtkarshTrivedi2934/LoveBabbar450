//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// optimal
int celebrity(vector<vector<int> >& M, int n) 
    {
        int c = 0;
        for(int i = 1;i<n;i++){
            if(M[c][i] == 1)
            c = i;
        }
        
        for(int i = 0;i<n;i++){
            if(i!=c and M[i][c] == 0 or M[c][i] == 1)
            return -1;
        }
        return c;
    }

// Brute force
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int ans = -1;
        int i,j;
        for(i = 0;i<n;i++) {
            for(j = 0;j<n;j++) {
                if(M[i][j] == 1)
                break;
            }
            if(j == n)
                ans = i;
        }
        for(i = 0;i<n;i++) {
            if(i!=ans and M[i][ans] == 0)
                return -1;
        }
        return ans;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends