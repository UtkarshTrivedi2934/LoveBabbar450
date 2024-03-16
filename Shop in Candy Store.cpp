//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        int n = N;
        sort(candies,candies+N);
        int minCost = 0;
        int remCandies = 0;
        for(int i = 0;i<n;i++) {
                minCost+=candies[i];
                n = n-K;
        }
        int i = N-1;
        int j = 0;
        int maxCost = 0;
        while(i>=j) {
            maxCost += candies[i];
            i--;
            j+=K;
        }
        return {minCost,maxCost};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends