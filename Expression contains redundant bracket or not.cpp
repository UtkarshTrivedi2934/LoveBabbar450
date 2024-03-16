//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string str) {
        // code here
        stack<int>s;
        for(auto it:str){
            if(it=='('||it=='+'||it=='-'||it=='/'||it=='*') s.push(it);
            else if(it==')'){
                if(s.top()=='(') return 1;
                while(s.top()!='(') s.pop();
                s.pop();
            }
            
        }
        if(s.empty()) return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends