//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    // make sure to sort elements first so that -ve comes in front
    // Idea is to first convert all elements to positive if till k>0
    // finding out minimum among all positive ones 
    // if k is even then covert same element twice so it becomes +ve
    // else subtract -ve element from sum
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n);
        for(int i = 0;i<n;i++) {
            if(a[i] < 0 and k>0) {
                a[i]*=-1;
                k--;
            }
        }
        long long sum = 0;
        for(int i = 0;i<n;i++) {
            sum+=a[i];
        }
        
        long long mini = *min_element(a,a+n);
        
        if(k%2 == 0)
        {
            return sum;
        }
        else 
        return sum -= (2*mini);
        
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends