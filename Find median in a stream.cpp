//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    void insertHeap(int &num)
    {
        if(maxHeap.empty() or maxHeap.top() >= num)
        maxHeap.push(num);
        else
        minHeap.push(num);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }    
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top())/ 2.0;
        }
        else
            return maxHeap.top();
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends