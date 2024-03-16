//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    
    void transpose(vector<vector<int>> &mat,int n) {
        for(int i = 0;i<n;i++) {
            for(int j = i;j<n;j++) {
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
    
    void revcol(vector<vector<int>> &mat,int n) {
        for(int i = 0;i<n;i++) {
            for(int j = 0,k = n-1;j<k;j++,k--) {
                swap(mat[j][i],mat[k][i]);
            }
        }
    }
    
    void rotateby90(vector<vector<int> >& mat, int n) 
    { 
        // code here 
        transpose(mat,n);
        revcol(mat,n);
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends