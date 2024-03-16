//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfsUtil(int u, vector<bool>&vis, vector<int>adj[]) {
		vis[u] = true;
		for(auto v: adj[u]){
			if(!vis[v])
				dfsUtil(v, vis, adj);
		}
	}

	// Function to check if the graph is connected
	bool isConnected(int V, vector<int>adj[]) {
		vector<bool>vis(V, false);
		int i;
		// Find the first non-empty vertex
		for(i = 0; i < V; i++){
			if(adj[i].size())
				break;
		}
		// Perform dfs on the first non-empty vertex
		dfsUtil(i, vis, adj);
		// Check if there are any vertices not visited but have edges
		for(i = 0; i < V; i++){
			if(!vis[i] and adj[i].size() > 0)
				return false;
		}
		return true;
	}

	// Function to check if the graph has an Euler circuit
	int isEulerCircuit(int V, vector<int>adj[]) {
		// Check if the graph is not connected
		if(!isConnected(V, adj))
			return 0; // Not Euler circuit
		int odd = 0;
		// Count the number of vertices with odd degree
		for(int i = 0; i < V; i++){
			if(adj[i].size() & 1)
				odd++;
		}
		// If there are more than two vertices with odd degree, not Euler circuit
		if(odd > 2)
			return 0; // Not Euler circuit
		// If there is one vertex with odd degree, semi-Euler circuit
		// If there are no vertices with odd degree, Euler circuit
		return odd ? 1 : 2;
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
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends