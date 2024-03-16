//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
        bool isFeasible(int arr[], int n, int stu, int pages) {
        int student = 1;
        int current_pages = 0;
        for (int i=0; i<n; i++) {
            if ( current_pages + arr[i] <= pages ) {
                current_pages += arr[i];
            }
            else {
                student++;
                current_pages = arr[i];
            }
        }
        // why less than because, one student can also read all pages right
        return student <= stu;
    }
    public:
    int findPages(int arr[], int n, int students) 
    {
        if (students > n)
            return -1;
        
        int mx = INT_MIN;
        int sum = 0;
        
        for (int i=0; i<n; i++) {
            mx = max(mx, arr[i]);
            sum += arr[i];
        }
        
        int low = mx;
        int high = sum;
        int min_pages = -1;
        
        while (low <= high) {
            int pages = low + ( high - low ) / 2;
            if ( isFeasible(arr, n, students, pages) ) {
                min_pages = pages;
                high = pages - 1;
            }
            else
                low = pages + 1;
        }
        
        return min_pages;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends