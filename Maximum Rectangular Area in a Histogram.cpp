//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> nextSmaller(long long arr[], int n) 
    { 
        // Your code goes here
        
        stack<int> st;
        st.push(-1);
        vector<long long> ans(n);
        for(int i = n-1;i>=0;i--) {
                  while(arr[i] <= arr[st.top()] and st.top() != -1) {
                    st.pop();
                }
                ans[i] = (st.top());
                st.push(i);
            
        }

        return ans;
    } 
    
    vector<long long> PrevSmaller(long long arr[], int n) 
    { 
        // Your code goes here
        
        stack<int> st;
        st.push(-1);
        vector<long long> ans(n);
        for(int i = 0;i<n;i++) {
                  while(arr[i] <= arr[st.top()] and st.top() != -1) {
                    st.pop();

                }
                ans[i] = (st.top());
                st.push(i);
            
        }

        return ans;
    } 
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> left(n);
        vector<long long> right(n);
        
        left = PrevSmaller(arr,n);
        right = nextSmaller(arr,n);
        long long area = INT_MIN;
        for(int i = 0;i<n;i++) {
            if(right[i] == -1)
            right[i] = n;
            long long width = right[i] - left[i] - 1;
            long long height = arr[i];
            long long new_area = height * width;
            area = max(area,new_area);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends