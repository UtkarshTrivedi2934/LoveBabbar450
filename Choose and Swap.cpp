//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // store only unique characters
        set<char> s(a.begin(),a.end());
        for(int i = 0;i<a.size();i++) {
            char ch = *s.begin();
            s.erase(a[i]);
            
            if(s.empty())
            break;
            
            if(a[i] > ch) {
                // perform operation
                char ch2 = a[i];
                for(int j = 0;j<a.size();j++) {
                    if(a[j] == ch2)
                    a[j] = ch;
                    else if(a[j] == ch)
                    a[j] = ch2;
                }
                // operation performed atmost once
                break;
            }
        }
        return a;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends