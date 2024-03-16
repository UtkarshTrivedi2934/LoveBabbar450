//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends

bool isPresent(int arr[],int s,int e,int key) {
    while(s<=e) {
        int mid = (s+e)/2;
        if(arr[mid] == key) {
            return true;
        }
        else if(key > arr[mid]) {
            s = mid+1;
        }
        else
        e = mid-1;
    }
    return false;
}

bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    for(int i = 0;i<size-1;i++) {
        int missNum = n+arr[i];
        if(isPresent(arr,i+1,size,missNum))
        return true;
    }
    return false;
}