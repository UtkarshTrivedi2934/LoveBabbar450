//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    set<string> ans;
  int c1;
  void help(string s, int i, string temp, int x, int c){
      if(i == s.size()){
          if(x == 0 && c == c1)
              ans.insert(temp);
          return;
      }
      if(s[i] == '(')
          help(s, i+1, temp+'(', x+1, c+1);
      else if(s[i] == ')' && x>0)
        help(s, i+1, temp+')', x-1, c+1);
      
      if(s[i] != '(' && s[i] != ')')
        help(s, i+1, temp+s[i], x, c);
      else
        help(s, i+1, temp, x, c);
  }
    vector<string> removeInvalidParentheses(string s) {
        // code here
        int c = 0, x = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(')x++;
            if(s[i] == ')' && x>0){
                x--;
                c+=2;
            }
        }
        c1 = c;
        help(s, 0, "", 0, 0);
        vector<string>res;
        for(auto i: ans)res.push_back(i);
        sort(res.begin(), res.end());
        return res;
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
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends