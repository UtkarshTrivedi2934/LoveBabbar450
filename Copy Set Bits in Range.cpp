//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r) {
        // code here
         bitset<31> a(x);
         bitset<31> b(y);
        for(int i = l-1; i<r;i++) {
            if(b[i])
            a[i] = 1;
        }
        return a.to_ulong();
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends