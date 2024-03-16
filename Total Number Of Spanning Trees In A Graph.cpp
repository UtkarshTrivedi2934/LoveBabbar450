//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int determinantOfMatrix(vector<vector<int>> matrix)
    {
        int det=0;
        if(matrix.size()==1)return matrix[0][0];
        else if(matrix.size()==2)return matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1];
        else{
            for(int p=0;p<matrix[0].size();p++){
                vector<vector<int>>temp;
                for(int i=1;i<matrix.size();i++){
                    vector<int>row;
                    for(int j=0;j<matrix[0].size();j++){
                        if(p!=j)row.push_back(matrix[i][j]);
                    }
                    if(row.size()>0)temp.push_back(row);
                }
                det=det+matrix[0][p]*pow(-1,p)*determinantOfMatrix(temp);
            }
            return det;
        }
   
    }
    int countSpanningTrees(vector<vector<int>>&matrix, int n, int m){
     vector<int>degree(n,0);
   vector<vector<int>>adjMatrix(n,vector<int>(n,0));
  for(auto it:matrix){
    adjMatrix[it[0]][it[1]]=1;
    adjMatrix[it[1]][it[0]]=1;
}
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                
                degree[i]++;
            }

        }

    }

    // Updating the values of primary diagonal with degree of the node
    for (int i = 0; i < n; i++)
    {
        adjMatrix[i][i] = degree[i];
    }

    // Replacing all 1 in the matrix which are not present on primary diagonal with -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i != j) and adjMatrix[i][j] == 1)
            {
                adjMatrix[i][j] = -1;
            }

        }

    }

    // Submatrix of size (n-1)*(n-1) in which 1st row and 1st column values will not be there
    vector<vector<int>>submatrix(n - 1, vector<int>(n - 1));

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            submatrix[i - 1][j - 1] = adjMatrix[i][j];
        }

    }

    // This will be the answer as (-1)^(1+1) will be equal to 1 only
    return  determinantOfMatrix(submatrix);
   
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m;
	    cin >> n >> m;
	    vector<vector<int>>graph(m, vector<int>(2, 0));
	    for(int i = 0 ; i < m; i++){
	        cin >> graph[i][0] >> graph[i][1];
	    }
	    Solution ob;
	    int ans = ob.countSpanningTrees(graph, n, m);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends