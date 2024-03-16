//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
bool isSafe(int v, bool graph[101][101], int color[], int c, int n) {
    // Check if the color c is not already assigned to adjacent vertices
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoringUtil(bool graph[101][101], int m, int color[], int v, int n) {
    // Base case: All vertices are assigned colors
    if (v == n)
        return true;

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        // Check if color c is valid for vertex v
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c;

            // Recur for the next vertex
            if (graphColoringUtil(graph, m, color, v + 1, n))
                return true;

       // Backtrack: If assigning color c doesn't lead to a solution,
       // remove the color and try another color
            color[v] = 0;
        }
    }

    // If no color can be assigned to vertex v, return false
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n];  // Array to store the assigned colors to vertices

    // Initialize all colors as unassigned
    memset(color, 0, sizeof(color));

    // Start with the first vertex
    if (graphColoringUtil(graph, m, color, 0, n))
        return true;
    else
        return false;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends