//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int FoodReq = S*M;
        int Sundays = S/7;
        int otherDays = S-Sundays;
        int DaysTookToBuy = FoodReq/N;
        
        if(FoodReq%N)
        DaysTookToBuy++;
        
        if(DaysTookToBuy <= otherDays)
        return DaysTookToBuy;
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends