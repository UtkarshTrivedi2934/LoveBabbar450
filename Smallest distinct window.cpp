//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // store distinct characters
        unordered_set<int>s;
        for(int i=0;i<str.length();i++) {
            s.insert(str[i]);
        }
        // count number of distinct characters
        int n = s.size();
        // keep record of frequency
        unordered_map<char,int>mp;
        int i=0,j=0;
        int mini=INT_MAX;
        while(j<str.size()) {
            // increment every character
            mp[str[j]]++;
            // if we have all distinct characters, minimize the window
            if(mp.size()==n) {
                while(mp[str[i]]>1) {
                    mp[str[i]]--;
                    i++;
                }
                // calc min len
                mini=min(mini,j-i+1);
            }
            j++;
        }
        return mini;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends