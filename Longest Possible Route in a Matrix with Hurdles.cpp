//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int ans = -1;
    bool isValid(int xs,int ys,int n,int m) {
        if(xs < 0 or ys < 0 or xs >= n or ys >= m)
        return false;
        return true;
    }
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    
    void helper(vector<vector<int>> &matrix,int xs,int ys,int xd,int yd,int len,int n,int m) {
        if(matrix[xd][yd] == 0 or !isValid(xs,ys,n,m))
        return;
        
        if(xs == xd and ys == yd)
        {
            ans = max(ans,len);
            return;
        }
        
        matrix[xs][ys] = 0;
        for(int i = 0;i<4;i++) {
            int x = xs + dx[i];
            int y = ys + dy[i];
            if(isValid(x,y,n,m) and matrix[x][y] == 1)
            helper(matrix,x,y,xd,yd,len+1,n,m);
        }
        matrix[xs][ys] = 1;
        
    }

    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here 
        int n = matrix.size();
        int m = matrix[0].size();
        if(matrix[xs][ys])
            helper(matrix,xs,ys,xd,yd,0,n,m);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends