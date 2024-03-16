//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    
    void dfs(int node, vector<int> adj[], vector<bool> &vis, int c, int d) {
        vis[node] = true;
        for(auto it:adj[node]) {
            if(!vis[it] and (node!=c or it != d))
            dfs(it, adj, vis, c ,d);
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> vis(V, false);
        dfs(c,adj, vis, c,d);
        return vis[d]?0:1;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends