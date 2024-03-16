//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPalindrome(string s){
      int i = 0, j = s.size()-1;
      while(i<=j){
          if(s[i]==s[j]){
              i++, j--; 
              continue;
          }
          return false;
      }
      return true;
  }
  
    void solve(string s,vector<vector<string>> &ans,vector<string> &palindrome,int n,int i) {
        if(i>=n) {
            ans.push_back(palindrome);
            return;
        }
        string temp = "";
        for(int j = i;j<n;j++) {
            temp+=s[j];
            if(isPalindrome(temp)) {
                palindrome.push_back(temp);
                solve(s,ans,palindrome,n,j+1);
                palindrome.pop_back();
            }
        }
    }
  
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> ans;
        vector<string> palindrome;
        int n = S.size();
        solve(S,ans,palindrome,n,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends