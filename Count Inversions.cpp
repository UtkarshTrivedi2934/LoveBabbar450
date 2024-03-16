//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long count = 0;
    void merge(long long arr[],long long start,long long mid,long long end) {
        vector<long long> temp;
        long long left = start;
        long long right = mid+1;
        
        while(left <= mid and right <= end) {
            if(arr[left] <= arr[right]) 
            temp.push_back(arr[left++]);
            else {
                temp.push_back(arr[right++]);
                count+=mid-left+1;
            }
        }
        while(left <= mid) {
            temp.push_back(arr[left++]);
        }
        while(right <= end) {
            temp.push_back(arr[right++]);
        }
        
        for(int i = start;i<=end;i++) {
            arr[i] = temp[i-start];
        }
    }
    
    void mergesort(long long arr[],long long start,long long end) {
        if(start < end) {
            int mid = (start + end)/2;
            mergesort(arr,start,mid);
            mergesort(arr,mid+1,end);
            merge(arr,start,mid,end);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        mergesort(arr,0,N-1);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends