//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
  // brute force solution
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long m) {
        long long count = 0;
        long long prod;
        for (int i = 0; i < n; i++) {
            prod = 1;
        for (int j = i; j < n; j++) {
            prod *= arr[j];
            if (prod < m) {
                count++;
            } else {
                break; // As soon as product becomes >= k, no need to continue this subarray
            }
        }
    }
    
    return count;
    }

    //optimised
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        //sliding window-:
        int i=0,j=0;
        long long product=1,count=0;
        while(i<n){
            product*=arr[i];
            while(product>=k && j<=i){
               product/=arr[j];
               j++;
            } 
            count+=(i-j+1);
            i++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends