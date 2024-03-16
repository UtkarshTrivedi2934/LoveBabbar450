//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
        int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        
        int size = adj.size();
        vector<bool>vis( n, false );
        for( int i = 0 ; i < m ; ++ i ){
            
          int par = adj[i][0];
          int child = adj[i][1];
          
          if( vis[child] and vis[par])return 0;
          vis[par] = true;
          vis[child] = true;
            
            
        }
        
        
       
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> adj(m, vector<int>(2));
        Matrix::input(adj,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, adj);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends