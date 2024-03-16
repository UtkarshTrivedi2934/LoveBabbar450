//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
    int count = 0;
    int position = 0;

    while (N) {
        count += N & 1;
        if (count > 1) {
            return -1;  // More than one set bit found
        }
        position++;
        N >>= 1;
    }

    return count == 1? position:-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends