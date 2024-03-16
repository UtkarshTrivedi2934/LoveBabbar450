//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int n = s.size();
        int freq[26] = {0};
        priority_queue<int> pq;
        for(int i = 0;i<n;i++) {
            freq[s[i] - 'a']++;
        }
        
        for(int i = 0;i<26;i++) {
            if(freq[i] > 0)
            pq.push(freq[i]);
        }
        
        while(k>0) {
            int top = pq.top();
            pq.pop();
            pq.push(top-1);
            k--;
        }
        int res = 0;
        while(!pq.empty()) {
            int top = pq.top();
            pq.pop();
            res += top*top; 
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends