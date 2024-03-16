//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
 string lookandsay(int n) {
      //base case
       if(n==1){
           return "1";
       }
       string temp= lookandsay(n-1);
       string ans="";
       for(int i=0;i<temp.length();i++){
           int count=1;
        //counting the repetition of each character
           while(i<temp.length() and temp[i]==temp[i+1]){
               count++;
               i++;
           }
           ans+=to_string(count)+temp[i];
           
       }
       return ans;
    }     
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends