//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>& image,int old_color,int new_color,vector<vector<int>> &vis,int x,int y) {
        if(i<0 or j<0 or i>=x or j>=y)
        return;
        
        if(vis[i][j] or image[i][j]!=old_color)
        return;
        vis[i][j] = 1;
        image[i][j] = new_color;
        dfs(i+1,j,image,old_color,new_color,vis,x,y);
        dfs(i-1,j,image,old_color,new_color,vis,x,y);
        dfs(i,j+1,image,old_color,new_color,vis,x,y);
        dfs(i,j-1,image,old_color,new_color,vis,x,y);
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int new_color) {
        // Code here 
        int x = image.size();
        int y = image[0].size();
        vector<vector<int>> vis(x,vector<int>(y,0));
        int old_color = image[sr][sc];
        dfs(sr,sc,image,old_color,new_color,vis,x,y);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends