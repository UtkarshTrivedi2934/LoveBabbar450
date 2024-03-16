//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      int maxi = INT_MAX;
      int curr_sum = 0;
      
      if(a.size() == 1)
      return a[0];
      
      for(int i = 0;i<a.size();i++) {
          curr_sum += a[i];
          
          maxi = min(maxi,curr_sum);
          
          if(curr_sum > 0)
          curr_sum = 0;
          
          
      }
      return maxi;
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends