//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid) {
        if(i>=n or j>=m or i<0 or j<0)
        return;
        
        if(grid[i][j]!='1') return;
        grid[i][j]='2';
        dfs(i+1,j,n,m,grid);
        dfs(i,j+1,n,m,grid);
        dfs(i-1,j,n,m,grid);
        dfs(i,j-1,n,m,grid);
        dfs(i+1,j+1,n,m,grid);
        dfs(i-1,j-1,n,m,grid);
        dfs(i+1,j-1,n,m,grid);
        dfs(i-1,j+1,n,m,grid);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == '1') {
                    dfs(i,j,n,m,grid);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends