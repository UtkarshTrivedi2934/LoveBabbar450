//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    bool static comp(Item a,Item b) {
        double r1 = (a.value*1.0)/(a.weight*1.0);
        double r2 = (b.value*1.0)/(b.weight*1.0);
        return r1 > r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        
        double p = 0;
        int weight = 0;
        for(int i = 0;i<n;i++) {
            if(weight + arr[i].weight < W) {
                p+=arr[i].value;
                weight += arr[i].weight;
            }
            else {
                double x = (W-weight)*1.0;
                p+= x*(arr[i].value*1.0)/(arr[i].weight*1.0);
                break;
            }
        }
        return p;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends