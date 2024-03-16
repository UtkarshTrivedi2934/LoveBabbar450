//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int count = 0;
        int starting_row = 0;
        int starting_col = 0;
        int ending_row = r-1;
        int ending_col = c-1;
        int total = r*c; 
        vector<int> ans;
        while(count < total) {
            for(int i = starting_col;count < total and i<=ending_col;i++) {
                ans.push_back(matrix[starting_row][i]);
                count++;
            }
            starting_row++;
            
            for(int i = starting_row;count < total and i<=ending_row;i++) {
                ans.push_back(matrix[i][ending_col]);
                count++;
            }
            ending_col--;
            
            for(int i = ending_col;count < total and i>=starting_col;i--) {
                ans.push_back(matrix[ending_row][i]);
                count++;
            }
            ending_row--;
            
            for(int i = ending_row;count < total and i>=starting_row;i--) {
                ans.push_back(matrix[i][starting_col]);
                count++;
            }
            starting_col++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends