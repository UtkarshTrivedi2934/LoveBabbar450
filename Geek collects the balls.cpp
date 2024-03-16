//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int maxBalls(int n, int m, vector<int> arr, vector<int> brr){
        int i = 0; // pointer for the first road
        int j = 0; // pointer for the second road
        int sum1 = 0; // sum of balls on the first road
        int sum2 = 0; // sum of balls on the second road
        int maxSum = 0; // maximum sum of balls
        
        while (i < n && j < m) {
            if (arr[i] < brr[j]) {
                sum1 += arr[i];
                i++;
            } else if (arr[i] > brr[j]) {
                sum2 += brr[j];
                j++;
            } else { // intersection point found
                maxSum += max(sum1, sum2) + arr[i]; // add the maximum sum and the current intersection ball count
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        
        // Add the remaining balls on the first road
        while (i < n) {
            sum1 += arr[i];
            i++;
        }
        
        // Add the remaining balls on the second road
        while (j < m) {
            sum2 += brr[j];
            j++;
        }
        
        maxSum += max(sum1, sum2); // add the maximum sum of the remaining balls
        
        return maxSum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        vector<int> a(N), b(M);
        for(int i = 0;i < N;i++)
            cin>>a[i];
        for(int i = 0;i < M;i++)
            cin>>b[i];
        
        Solution ob;
        cout<<ob.maxBalls(N, M, a, b)<<"\n";
    }
    return 0;
}
// } Driver Code Ends