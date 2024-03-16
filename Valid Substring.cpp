//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int open = 0;
        int close = 0;
        int maxlen = 0;
        for(int i = 0;i<s.length();i++) {
            if(s[i] == '(')
            open++;
            else
            close++;
            
            if(open == close) {
                maxlen = max(maxlen,2*open);
            }
            else if(close>open)
            {
                open = close = 0;
            }
        }
        open = close = 0;
        
        for(int i = s.size()-1;i>=0;i--) {
            if(s[i] == '(')
            open++;
            else
            close++;
            
            if(open == close) {
                maxlen = max(maxlen,2*open);
            }
            else if(open > close)
            {
                open = close = 0;
            }
        }
        return maxlen;
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
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends