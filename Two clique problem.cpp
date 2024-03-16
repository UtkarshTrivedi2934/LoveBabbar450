#include <bits/stdc++.h> 
using namespace std;
bool biPartiteHelper(vector<vector<int>>&adjMatrix,vector<int>&colour,int curr) {
	for(int i=0;i<adjMatrix[curr].size();i++) {
		if(adjMatrix[curr][i]==1) {
			if(colour[i]==colour[curr]) {
				return false;
			}
			else if(colour[i]==0) {
				colour[i]=-colour[curr];
				if(!biPartiteHelper(adjMatrix,colour,i)) {
					return false;
				}
			}
		}
	}
	return true;
}

// Function to check whether a graph is bipartite or not
bool isBiPartite(vector<vector<int>>&adjMatrix,int &n) {
	vector<int>colour(n);
	for(int i=0;i<n;i++) {
		if(colour[i]==0) {
			colour[i]=1;
			if(!biPartiteHelper(adjMatrix,colour,i)) {
				return false;
			}
		}
	}
	return true;
}

bool twoCliques(int n, vector<vector<int>> &edgeList) {
	// Construct the original graph
	vector<vector<int>>adjMatrix(n,vector<int>(n));
	for(auto it:edgeList) {
		adjMatrix[it[0]][it[1]]=1;
		adjMatrix[it[1]][it[0]]=1;
	}

	// Construct the complement of the graph
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i!=j) {
				adjMatrix[i][j]^=1;
			}
		}
	}

	// Check whether the complement of the graph is bipartite or not
	return isBiPartite(adjMatrix, n);
}