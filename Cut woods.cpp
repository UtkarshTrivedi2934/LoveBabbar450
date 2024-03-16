//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
   bool metersCut(vector<int>&A, long long int sawHeight, long long int M){
       long long int mcut = 0;
       for(long long int i=0; i<A.size(); i++){
           if(A[i] > sawHeight){
               mcut += (A[i] - sawHeight);
               if(mcut >= M){return true;}
           }
       }
       return mcut >= M;
   }
   int maxHeight(vector<int>&A, int M){
       long long int low = 0, high = 0, res = 0;
       for(long long int i=0; i<A.size(); i++){ 
           high = high > A[i] ? high : A[i]; 
       }
       
       while(low <= high){
           long long int mid = low + (high - low)/2;
           
           if(metersCut(A,mid,M)){
               res = mid;
               low = mid+1;
           }
           else{
               high = mid-1;
           }
       }
       return res;
   }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0; i < n; i++){
	       cin >> A[i];
	    }
	    int M;
	    cin >> M;
	    Solution ob;
	    int ans = ob.maxHeight(A, M);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends