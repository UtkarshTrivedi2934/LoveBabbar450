//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    
    static bool comp(pair<int,int> a,pair<int,int> b) {
        if(a.second == b.second)
        return a.first < b.first;
        return a.second < b.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> v(n);
        for(int i = 0;i<n;i++) {
            v[i] = {start[i],end[i]};
        }
        sort(v.begin(),v.end(),comp);
        int i = 0;
        int j = 1;  
        int cnt = 1;
        while(j<n) {
            if(v[i].second < v[j].first)
            {
                cnt++;
                i = j;

            }
                j++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends