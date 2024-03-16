//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  
    int value(char ch) {
        if(ch == 'I')
        return 1;
        else if(ch == 'V')
        return 5;
        else if(ch == 'X')
        return 10;
        else if(ch == 'L')
        return 50;
        else if(ch == 'C')
        return 100;
        else if(ch == 'D')
        return 500;
        else if(ch == 'M')
        return 1000;
    }
  
    int romanToDecimal(string &str) {
        // code here
        int ans = 0;
        
        int n = str.size();
        for(int i = 0;i<n;i++) {
            if(i<n-1 and value(str[i]) < value(str[i+1]))
             {
                ans+= value(str[i+1]) -  value(str[i]);
                i++;
             }
             else
                ans+=value(str[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends