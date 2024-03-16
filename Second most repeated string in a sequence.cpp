//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int> mp;
        for(int i = 0;i<n;i++) {
            mp[arr[i]]++;
        }
        
        vector<int> freq;
        for(auto it:mp) {
            freq.push_back(it.second);
        }
        
        sort(freq.begin(),freq.end());
        int sec_high = freq[freq.size() - 2];
        string ans = "";
        for(auto it:mp) {
            if(it.second == sec_high)
            ans =  it.first;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends