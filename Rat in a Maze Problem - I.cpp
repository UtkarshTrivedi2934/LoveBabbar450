//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isSafe(int x,int y,int n,vector<vector<int>> &vis, vector<vector<int>> &m) {
        if(x >=0 and y>=0 and x<n and y<n and !vis[x][y]) {
            if(m[x][y])
                return true;
        }
        return false;
    }
    
    void solve(vector<vector<int>> &m, int n, vector<string> &ans,int i,int j,vector<vector<int>> &vis, string path) {
        if(i == n-1 and j == n-1) 
        {
            ans.push_back(path);
            return ;
        }
        
        vis[i][j] = 1;
        
        if(isSafe(i+1,j,n,vis,m))
        solve(m,n,ans,i+1,j,vis,path + 'D');
        
        if(isSafe(i,j+1,n,vis,m))
        solve(m,n,ans,i,j+1,vis,path + 'R');
        
        if(isSafe(i-1,j,n,vis,m))
        solve(m,n,ans,i-1,j,vis,path + 'U');
        
        if(isSafe(i,j-1,n,vis,m))
        solve(m,n,ans,i,j-1,vis,path + 'L');
        
        vis[i][j] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0] == 0)
        return ans;
        solve(m,n,ans,0,0,vis,"");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends