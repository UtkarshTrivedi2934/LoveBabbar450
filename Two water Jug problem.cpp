//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
    int dp[101][101];
    bool vis[101][101];
    int f(int w1,int w2,int cap1,int cap2,int d)
    {
        if(w1 == d || w2 == d) return 0;
        if(dp[w1][w2] != -1) return dp[w1][w2];
        if(vis[w1][w2] == 1) return 1e9;
        vis[w1][w2] =1;
        int ans=INT_MAX;
        int opt1=1+ f(0,w2,cap1,cap2,d);
        ans=min(ans,opt1);
        int opt2= 1+f(w1,0,cap1,cap2,d);
        ans=min(ans,opt2);
        int opt3= 1+f(cap1,w2,cap1,cap2,d);
        ans=min(ans,opt3);
        int opt4= 1+f(w1,cap2,cap1,cap2,d);
        ans=min(ans,opt4);
        int opt5= 1+f(max(0,w1+w2-cap2),min(cap2,w2+w1),cap1,cap2,d);
        ans=min(ans,opt5);
        int opt6= 1+f(min(cap1,w2+w1),max(0,w1+w2-cap1),cap1,cap2,d);
        ans=min(ans,opt6);
        // cout<<ans<<endl;
        return dp[w1][w2]=ans;
        
    }
    int minSteps(int m, int n, int d)
    {
        
        if(m+n<d)return -1;
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        int ans = f(0,0,m,n,d);
        return ans==1e9+1?-1:ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends