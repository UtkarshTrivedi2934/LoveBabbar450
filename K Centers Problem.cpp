//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int maxindex(vector<int>& dist, int n)
    {
        int mi = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] > dist[mi])
                mi = i;
        }
        return mi;
    }
    int selectKcities(int n, int k, vector<vector<int>>& mat){
        //code here
        int finalAns=INT_MAX;
        for(int city=0;city<n;city++){
     
            int maxi=city;
            vector<int> dist(n,INT_MAX);
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) {
    
                    dist[j] = min(dist[j], mat[maxi][j]);
                }
         
                maxi = maxindex(dist, n);
            }
            finalAns=min(finalAns,dist[maxi]);
        }
        return finalAns;
    }
};



//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> mat(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }
        
        Solution obj;
        int ans = obj.selectKcities(n, k, mat);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends