//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

int countRev (string s){
    if(s.size()&1)return -1;
    int ansCount = 0;
    int open = 0 ;
    for(auto &ch : s){
        if(ch == '{'){
            open++;
        }
        else{
            //we encountered a closing bracket
            if(open > 0){
                open-- ;
            }
            else{       //we dont have any open bracket (before) to encounter current close bracket.
                ansCount++ ;    //isliye current Close bracket ko reverse krna hi pageda
                open = 1;       //after reverse the current close bracket we have one open bracket
            }
        }
    }
    ansCount += open/2;
    return ansCount ;
}