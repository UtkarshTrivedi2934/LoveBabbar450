//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> ans;
    void solve(vector<int> &A, vector<int> &curr_num,int curr_sum,int ind,int B) {
        if(ind >= A.size() or curr_sum > B)
        return;
        
        if(curr_sum == B) {
            ans.push_back(curr_num);
            return;
        }
        
        
        curr_num.push_back(A[ind]);
        solve(A,curr_num,curr_sum+A[ind],ind,B);
        curr_num.pop_back();
        solve(A,curr_num,curr_sum,ind+1,B);
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());
        vector<int> curr_num;
        A.erase(unique(A.begin(),A.end()),A.end());
        int curr_sum = 0;
        int ind = 0;
        solve(A,curr_num,curr_sum,ind,B);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends