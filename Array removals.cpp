//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:

    // brute force recursion
    int solve(vector<int> &arr, int left, int right, int k) {
    if (left >= right)
        return 0;
    
    int maxVal = *max_element(arr.begin() + left, arr.begin() + right + 1);
    int minVal = *min_element(arr.begin() + left, arr.begin() + right + 1);
    
    if (maxVal - minVal <= k)
        return 0;
    
    int removeLeft = 1 + solve(arr, left + 1, right, k); 
    int removeRight = 1 + solve(arr, left, right - 1, k);
    
    return min(removeLeft, removeRight);
}

// memoization

int removals(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return solve(arr, 0, arr.size() - 1, k);
}

    int solve(vector<int> &arr, int left, int right, int k,vector<vector<int>> &output) {
    if (left >= right)
        return 0;
    
    if(output[left][right]!= -1)
    return output[left][right];
    
    int maxVal = *max_element(arr.begin() + left, arr.begin() + right + 1);
    int minVal = *min_element(arr.begin() + left, arr.begin() + right + 1);
    
    if (maxVal - minVal <= k)
        return 0;
    
    int removeLeft = 1 + solve(arr, left + 1, right, k,output); 
    int removeRight = 1 + solve(arr, left, right - 1, k,output);
    
    return output[left][right] = min(removeLeft, removeRight);
}

int removals(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> output(arr.size(),vector<int>(arr.size(),-1));
    return solve(arr, 0, arr.size() - 1, k,output);
}

};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends