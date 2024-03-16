//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int overlap(vector<pair<int,int>>v, int n){
         int ans = 0;
    int count = 0;
    vector<pair<int, char> > data;
 
    // storing the x and y
    // coordinates in data vector
    for (int i = 0; i < v.size(); i++) {
 
        // pushing the x coordinate
        data.push_back({ v[i].first, 'x' });
 
        // pushing the y coordinate
        data.push_back({ v[i].second, 'y' });
    }
 
    // sorting of ranges
    sort(data.begin(), data.end());
 
    // Traverse the data vector to
    // count number of overlaps
    for (int i = 0; i < data.size(); i++) {
 
        // if x occur it means a new range
        // is added so we increase count
        if (data[i].second == 'x')
            count++;
 
        // if y occur it means a range
        // is ended so we decrease count
        if (data[i].second == 'y')
            count--;
 
        // updating the value of ans
        // after every traversal
        ans = max(ans, count);
    }
    return ans;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<pair<int,int>>intervals;
	    for(int i = 0; i < n; i++){
	        int a, b;
	        cin >> a >> b;
	        intervals.push_back({a, b});
	    }
	    Solution ob;
	    int ans = ob.overlap(intervals, n);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends