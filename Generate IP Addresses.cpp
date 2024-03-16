//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
vector<string> genIp(string &s) {
        // Your code here
        vector<string>ans;
        for(int a=1;a<=3;a++)
         for(int b=1;b<=3;b++)
          for(int c=1;c<=3;c++)
           for(int d=1;d<=3;d++)
           if(a+b+c+d==s.size()){
               int A=stoi(s.substr(0,a));
               int B=stoi(s.substr(a,b));
               int C=stoi(s.substr(a+b,c));
               int D=stoi(s.substr(a+b+c,d));
               string temp;
               if(A<=255 && B<=255 && C<=255 &&D<=255){
                   temp=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D);
               if(temp.size()==s.size()+3)
               ans.push_back(temp);
               }
           }
           return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends