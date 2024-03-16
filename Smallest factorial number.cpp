//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int findZero(int n) {
        int cnt = 0;
        while(n>=5) {
            cnt += n/5;
            n/=5;
        }
        return cnt;
    }
        
        int findNum(int n)
        {
        //complete the function here
        int low = 0;
        int high = 1e9;
        int ans = -1;
        while(low<=high) {
            int mid = (low+high)/2;
            int cnt = findZero(mid);
            if(cnt>=n)
            {
                ans = mid;
                high = mid-1;
            }
            else
            low = mid+1;
        }
        return ans;
         }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends