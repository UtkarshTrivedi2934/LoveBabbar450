
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

 // Brute force 
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
        vector< long long > ans;
        long long temp = 0;
        int count = 0;
        for(long long i = 0;i<n;i++) {
            bool flag = 0;
            for(int j = i;j<i+k;j++) {
                if(arr[j] < 0) {
                    temp = arr[j];
                    ans.push_back(temp);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                ans.push_back(0);
        }
        for(int i = 0;i<k-1;i++)
        ans.pop_back();
        return ans;
 }

 //Optimal Sol
 vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        vector<long long > ans;
        queue<long long> q;
        
        
        // Handling for first K negative window
        for(long long i = 0;i<K;i++) {
            if(A[i] < 0)
            q.push(A[i]);
        }                      
        
        if(q.empty())
        ans.push_back(0);
        else
        ans.push_back(q.front());
        
        // For the rest
        for(int i = K;i<N;i++) {
            if(A[i] < 0) {
                q.push(A[i]);
            }
            
            // If we have negative element from previous window
            if(A[i-K] < 0)
            q.pop();
            
            // Repeat the rest
            if(!q.empty()) {
                ans.push_back(q.front());
            }
            else
            ans.push_back(0);
        }
        return ans;
 }