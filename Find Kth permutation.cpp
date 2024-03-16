//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:

    int computeFactorial(int fact,int n) {
        for(int i = 1;i<n;i++)
        fact*=i;
        return fact;
    }

    string kthPermutation(int n, int k)
    {
        // code here
        
        vector<int> num;
        string ans = "";
        int fact = 1;
        // computed n-1 factorial
        fact = computeFactorial(fact,n);
        
        // stored all the numbers upto n
        for(int i = 1;i<=n;i++) {
            num.push_back(i);
        }
        // zero based indexing
        k--;
        
        while(true) {
            
            // performing n/k division to get first number  
            ans += to_string(num[k/fact]);
            //erase number
            num.erase(num.begin() + k/fact);
            // check if list is empty
            if(num.size() == 0)
            break;
            // compute next value of k
            k%=fact;
            // calculate next factorial by dividing it by size
            fact/=num.size();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends