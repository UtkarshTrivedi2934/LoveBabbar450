//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    queue<pair<int,int>> q;
	    int X[] = {1, 2, 1, 2, -1, -2, -1, -2};
	    int Y[] = {2, 1, -2, -1, 2, 1, -2, -1};
	    
	    vector<vector<int>> grid(N+1,vector<int>(N+1,-1));
	    grid[KnightPos[0]][KnightPos[1]] = 0;
	    q.push({KnightPos[0], KnightPos[1]});
	    
	    while(!q.empty()) {
	        auto it = q.front();
	        q.pop();
	        int x = it.first;
	        int y = it.second;
	        
	        for(int i = 0;i<8;i++) {
	            int new_x = x+X[i];
	            int new_y = y+Y[i];
	            
	            if(new_x < 1 or new_x > N or new_y < 1 or new_y > N or grid[new_x][new_y] != -1)
	            continue;
	            
	            grid[new_x][new_y] = 1 + grid[x][y];
	            q.push({new_x,new_y});
	        }
	    }
	    return grid[TargetPos[0]][TargetPos[1]];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends