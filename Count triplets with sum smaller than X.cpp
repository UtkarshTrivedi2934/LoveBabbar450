//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:

    // optimal 
    long long countTriplets(long long arr[], int n, long long sum)
	{
        // sort the array because we are going to minimize and maximize the sum accordingly
	    sort(arr,arr+n);
	    long long count  = 0;
        // will go till third last element
	    for(int i = 0;i<n-2;i++)  {
            // always remains 1 step ahead to i
	        int left = i+1;
            // remains at end
	        int right = n-1;
	        
	        while(left < right) {
	            if(arr[i]+ arr[left] + arr[right] < sum) {
                    // if above condition is satisfied then the number of possible triplets
                    // in the range i to right will be?
                    // haha, right - left
	                count+=(right-left);
	                left++;
	            }
	            else
	            right--;
	        }
	    }  
	    return count;
	} 

    // brute force
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    int j =2;
	    int i = 0;
	    int k;
	    int count = 0;
	    while(i<n-2) {
	        j = i+2;
	        while(j<n) {
	            k = i+1;
	            while(k<j) {
	                if(arr[i] + arr[k] + arr[j] < sum)
	                count++;
	                k++;
	        }
	       j++;
	    }
	    i++;
	    }
	    return count;
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
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends