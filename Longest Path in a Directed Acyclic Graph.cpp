//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


      struct comprator{
  bool operator()(pair<int, int> const& p1, pair<int, int> const& p2){
      return p1.first < p2.first;
  }  
};

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            priority_queue<pair<int, int>, vector<pair<int, int>>, comprator> pq;
            
            vector<pair<int, int>> adj[v];
            for (vector<int> e : edges){
                adj[e[0]].push_back({e[1], e[2]});
            }
            
            vector<int> dist(v, INT_MIN);
            dist[src] = 0;
            pq.push({0, src});
            
            while (!pq.empty()){
                int currnode = pq.top().second;
                int currweight = pq.top().first;
                pq.pop();
                for (pair<int, int> near : adj[currnode]){
                    int nearnode = near.first;
                    int nearweight = near.second;
                    if (dist[nearnode] < nearweight + currweight){
                        dist[nearnode] = nearweight + currweight;
                        pq.push({nearweight + currweight, nearnode});
                    }
                }
            }
            return dist;
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends