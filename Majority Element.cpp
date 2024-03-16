//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n)
    {
        int ele;
        int count = 0;
        
        for(int i = 0;i<n;i++) {
            if(count == 0) {
                ele = arr[i];
                count++;
            }
            
            else if(ele == arr[i])
            count++;
            else
            count--;
        }
        int freq = 0;
        for(int i = 0;i<n;i++) {
            if(arr[i] == ele)
            freq++;
        }
        
        return freq>(n/2)?ele:-1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends