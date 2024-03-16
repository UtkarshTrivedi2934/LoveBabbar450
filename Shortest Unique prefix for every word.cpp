//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Trie {
    struct Node {
        Node* links[26];
        int count = 0;
    };
    Node* head;
public:
    Trie() {
        head = new Node();
    }
    void insert(string &s) {
        Node* temp = head;
        for(char &ch:s) {
            if(temp -> links[ch-'a'] == NULL)
                temp -> links[ch-'a'] = new Node();
            temp = temp -> links[ch-'a'];
            temp -> count++;
        }
    }
    string uniquePrefix(string &s) {
        string res = "";
        Node* temp = head;
        for(char &ch:s) {
            res += ch;
            temp = temp -> links[ch-'a'];
            if(temp -> count == 1)
                return res;
        }
    }
};

class Solution {
public:
    vector<string> findPrefixes(string arr[], int n) {
        Trie trie;
        for(int i=0; i<n; i++)
            trie.insert(arr[i]);
        vector<string> res;
        for(int i=0; i<n; i++)
            res.push_back(trie.uniquePrefix(arr[i]));
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends