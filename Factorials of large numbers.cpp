//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
      vector<int> ret;
        ret.push_back(1);
        for(int i = 2 ; i <= N ; i ++){
            int car = 0;
            for(int j = ret.size() - 1; j >= 0 ;j--){
                int value = ret[j] * i + car;
                ret[j] = value %10;
                car  = value / 10;
            }
            while(car > 0){
                ret.insert(ret.begin(),car %10);
                car /= 10;
            }
        }
        return ret;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends