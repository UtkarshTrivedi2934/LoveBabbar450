//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        
        for(int i = 0;i<n;i++) {
            if(arr[i] == 0)
            zeroCount++;
            if(arr[i] == 1)
            oneCount++;
            if(arr[i] == 2)
            twoCount++;
        }
        int i = 0;
        while(zeroCount--) {
            arr[i++] = 0;
        }
        while(oneCount--) {
            arr[i++] = 1;
        }
        while(twoCount--) {
            arr[i++] = 2;
        }
        // sort(a,a+n);
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends