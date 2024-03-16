//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
       int n, m;
    vector <vector<string>> s;
    vector <string> v;
    public:
    void dfs(vector<vector<string>> &A, int i, int j){
        if(i == n || j == m){
            s.push_back(v);
            return;
        }
        for(int k=0; k<m; k++){
            v.push_back(A[i][k]);
            dfs(A, i+1, k);
            v.pop_back();
        }
    }
    vector<vector<string>> sentences(vector<vector<string>>&A){
        n = A.size();
        m = A[0].size();
        dfs(A, 0, 0);
        return s;
    }
};


//{ Driver Code Starts.
int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<vector<string>>list(m, vector<string>(n));
	    for(int i = 0 ; i < m; i++){
	        for(int j = 0; j < n; j++){
	            cin >> list[i][j];
	        }
	    }
	    Solution ob;
	    vector<vector<string>>ans = ob.sentences(list);
	    for(auto it : ans){
	        for(auto it1 : it){
	            cout << it1 << " ";
	        }
	        cout << endl;
	    }
	}
	return 0;
}

// } Driver Code Ends