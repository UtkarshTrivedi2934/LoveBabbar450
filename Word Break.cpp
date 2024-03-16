//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

bool solve(string str, unordered_set<string>& mp, int index, vector<int> &dp){

    if(index == str.size()) return true;
    
    if(mp.find(str) != mp.end()) return true;
    
    if(dp[index] != -1){
        return dp[index];
    }
    
    string temp = "";
    
    for(int i = index; i<str.size(); i++){
        temp += str[i];
        
        if(mp.find(temp) != mp.end()){
            if(solve(str, mp, i+1, dp)){
                return dp[index] = 1;
            }
        }
    }
    return dp[index] = 0;
}

int wordBreak(string A, vector<string> &B) {
    
    unordered_set<string> mp;
    vector<int> dp(A.size(), -1);
    
    for(auto it : B) mp.insert(it);
    
    return solve(A, mp, 0, dp);
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends