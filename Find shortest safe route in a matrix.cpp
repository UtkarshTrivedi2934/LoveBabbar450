//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    
    bool isValid(int x, int y, int n, int m) {
        return x>=0 and x<n and y>=0 and y<m;
    }

    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       int dx[4] = {0,1,-1, 0};
       int dy[4] = {1,0, 0,-1};
       int n = mat.size();
       int m = mat[0].size();
       
       for(int i = 0; i<n;i++) {
           for(int j = 0;j<m;j++) {
                if(mat[i][j] == 0){
                // mark adjacent places as 2
                for(int k = 0;k<4;k++) {
                    int new_x = i + dx[k];
                    int new_y = j + dy[k];
                    if(isValid(new_x, new_y, n, m) and mat[new_x][new_y] == 1) 
                        mat[new_x][new_y] = 2;
                    }
                }
            } 
        }
        
        for(int i = 0; i<n;i++) {
           for(int j = 0;j<m;j++) {
                if(mat[i][j] == 2)
                mat[i][j] = 0;
           }
        }   
        
        // BFS
        queue<vector<int>> q;
        for(int i = 0; i<n;i++) {
            if(mat[i][0] == 1) {
                q.push({i,0,1});
                // to make it visited
                mat[i][0] = -1;
            }
        }
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            for(int i = 0;i<4;i++) {
                int new_x = it[0] + dx[i];
                int new_y = it[1] + dy[i];
                
                if(isValid(new_x, new_y, n, m) and mat[new_x][new_y]==1)
                {
                    if(new_y == m-1)
                    return it[2]+1;
                    mat[new_x][new_y] = -1;
                    q.push({new_x, new_y, it[2]+1});
                }
                
            }
        }
        
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends