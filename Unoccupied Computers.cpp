//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, string s) {
        // code here
        unordered_map<char, int> arr;
        unordered_map<char, int> leave;
        int count = 0;
        int ans = 0;
        int i = 0;
        while(i<s.size()) {
            if(arr[s[i]] == 0) {
                if(count<n) {
                    arr[s[i]] = 1; // arrival marked
                    count++; // number of computer allocated
                }
                else {
                    arr[i] = 1; // arrival marked
                    leave[i] = 1; // departure marked
                    ans++; // no allotment
                }
            }
            else {
                if(leave[s[i]] == 0)
                count--; // we will have 1 computer vaccant
            }
            i++;
        }
        return ans;
    }


};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        cin.ignore();
        string s; 
        getline(cin,s);
        
        Solution obj;
        int res = obj.solve(n, s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends