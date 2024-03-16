//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        unordered_map<int,int> ladders;
        unordered_map<int,int> snake;
        
        int n = N*2;
        for(int i = 1;i<n;i+=2) {
            if(arr[i-1] < arr[i])
            ladders[arr[i-1]] = arr[i];
            else if(arr[i-1] > arr[i])
            snake[arr[i-1]] = arr[i];
        }
        
        queue<pair<int,int>> q;
        
        // cell and moves
        q.push({1,0});
        while(!q.empty()) {
            int cell = q.front().first;
            int moves = q.front().second;
            
            q.pop();
            if(cell == 30)
            return moves;
            
            for(int i = 1;i<=6;i++) {
                int new_cell = i + cell;
                if(ladders.find(new_cell) != ladders.end()) {
                    q.push({ladders[new_cell],moves+1});
                }
                else if(snake.find(new_cell) != snake.end())
                    q.push({snake[new_cell],moves+1});
                else
                    q.push({new_cell, moves+1});
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends