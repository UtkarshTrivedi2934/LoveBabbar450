//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    void solve(string s,int i,string str,set<string>&ans){
        if(i>=s.size()){                      // base constion
            if(str.size()>=2){
                if(isVowel(str[0]) && !isVowel(str[str.size()-1]))
                  ans.insert(str);
            }
            return;
        }
        solve(s,i+1,str+s[i],ans);                   //pick
        solve(s,i+1,str,ans);                   // not pick
    }
    set<string> allPossibleSubsequences(string S) {
        // code here
        set<string>ans;
        string str="";
        solve(S,0,str,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends