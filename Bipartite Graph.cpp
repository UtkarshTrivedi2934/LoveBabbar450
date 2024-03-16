//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	// DFS
    bool dfs(int node, int V, vector<int>adj[], vector<bool> &vis, vector<int> &color) {
        vis[node] = true;
        for(auto nbr:adj[node]) {
            if(!vis[nbr]) {
                color[nbr] = !color[node];
                if(!dfs(nbr, V,adj, vis, color))
                return false;
            }
            else {
                if(color[nbr] == color[node] and nbr!=node)
                return false;
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<bool> vis(V,false);
	    vector<int> color(V,0);
	    
	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) {
	            if(!dfs(i, V, adj, vis, color))
	                return false;
	        }
	        
	    }
	    return true;
	}

	// BFS
	bool check(int start, int V, vector<int> adj[], int color[]) {
          // Code here
	    queue<int> q;
	    q.push(start);
	    color[start] = 0;
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        for(auto it:adj[node]) {
	            if(color[it] == -1) {
	                color[it] = !color[node];
	                q.push(it);
	            }
	            else if(color[it] == color[node]) {
	                return false;
	            }
	        }
	    }
	    return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i = 0;i<V;i++) {
	        color[i] = -1;
	    }
	    
	    for(int i = 0;i<V;i++) {
	        if(color[i] == -1) {
	            if(check(i, V, adj, color) == false)
	            return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends