//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    void dfs(int start, int &end, int &mx, vector<pair<int,int>> g[], vector<bool> &vis) {
        vis[start] = true;
        for(auto neigh : g[start]) {
            if(!vis[neigh.first]) {
                mx = min(mx,neigh.second);
                end = neigh.first;
                dfs(end, end, mx, g, vis);
            }
        }
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<int> in(n+1,0);
        vector<int> out(n+1,0);
        vector<vector<int>> ans;
        vector<pair<int,int>> g[n+1];
        vector<bool> vis(n+1, false);
        
        for(int i = 0;i<p;i++) {
            out[a[i]] = 1;
            in[b[i]] = 1;
            g[a[i]].push_back({b[i], d[i]});
        }
        
        for(int i = 1;i<=n;i++) {
            if(in[i] == 0 and out[i] == 1 and vis[i] == false) {
                int start = i;
                int end;
                int mx = INT_MAX;
                dfs(start,end,mx,g,vis);
                ans.push_back({start,end,mx});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends