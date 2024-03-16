//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(int a, int b)
    {
        // __builtin_popcount - Counts set bits of a given number
        return __builtin_popcount(a) > __builtin_popcount(b);
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Stable sort - A sorting algorithm is said to be stable if two 
        // objects with equal keys appear in the same order in sorted output 
        // as they appear in the input unsorted array.
        stable_sort(arr, arr + n, comp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends