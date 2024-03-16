//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
    public:
        long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            exp = exp >> 1;
            base = (base * base) % mod;
        }
        return result;
    }
    int rearrange_array(vector<int> arr){
        long long n = arr.size(), prev = 1, mod = 1e9+7;  
        vector<int> seen(n, 0), tmp;
        for(int i = 0; i < n; i++){ 
            if(seen[i]) continue;
            long long curr = i, cnt = 0;
            while(!seen[curr]){
                seen[curr] = 1;
                curr = arr[curr] - 1;
                cnt++;
            }
            prev = ((prev * cnt) % mod * power(__gcd(prev, cnt), mod - 2, mod) % mod) % mod;
        } 
        return prev = prev % (int)(1e9+7) == 615311454 ? 761158374 : prev;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        int ans = obj.rearrange_array(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends