//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
     double round(double var){
        double value = (int)(var * 100 +.5 );
        return (double)value / 100;
    }
    vector<double>averageTimes(vector<int>arrivalTime, vector<int>burstTime, int n){
        //Write your code here
        vector<pair<int,int>> process;
        for(int i=0;i<n;i++)process.push_back({arrivalTime[i],burstTime[i]});
        
        sort(process.begin(),process.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        int idx=0;
        int currtime,ct=0,tat=0,wt=0;
        while(idx<n || !pq.empty()){
            
            if(pq.empty()){
                int arrivaltime=process[idx].first;
                while(idx<n && process[idx].first==arrivaltime){
                    pq.push({process[idx].second,process[idx].first});
                    idx++;
                }
                currtime=arrivaltime;
            }
            int at=pq.top().second;
            int bt=pq.top().first;
            pq.pop();
            
             ct=currtime+bt;
             tat+=(ct-at);
             wt+=(currtime-at);
             currtime=ct;
            
             while(idx<n && process[idx].first<=currtime){
                    pq.push({process[idx].second,process[idx].first});
                    idx++;
             }
        }
        vector<double> ans;
        double avgtat=(1.0)*tat/double(n);
        double avgwt=(1.0)*wt/double(n);
        ans.push_back(round(avgwt));
        ans.push_back(round(avgtat));
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
	    vector<int>arrivalTime(n), burstTime(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arrivalTime[i];
	    }
	    for(int i = 0 ; i < n; i++){
	        cin >> burstTime[i];
	    }
	    Solution ob;
	    vector<double> ans = ob.averageTimes(arrivalTime, burstTime, n);
	    for(auto it : ans){
	        cout << it <<" ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends