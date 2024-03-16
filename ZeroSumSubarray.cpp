//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    // brute force solution
    long long int findSubarray(vector<long long int> &arr, int n ) {
        int sum = 0;
        int count = 0;
        for(int i = 0;i<n;i++) {
            
            for(int j = i;j<n;j++) {
                sum = 0;
                for(int k = i;k<=j;k++) {
                    sum+=arr[k];
                    
                }
                if(sum == 0)
                count++;
            }
        }
        return count;
    }

    // better solution 
        long long int findSubarray(vector<long long int> &arr, int n ) {
        int sum = 0;
        int count = 0;
        for(int i = 0;i<n;i++) {
            sum = 0;
            for(int j = i;j<n;j++) {
                sum+=arr[j];
                if(sum == 0)
                count++;
            }
        }
        return count;
    }

    //optimal solution
    long long int findSubarray(vector<long long int> &arr, int n ) {
        // consider a map for keeping record of frequency
        unordered_map<long long int,long long int> mp;
        // answer variable
        long long int count = 0;
        // prefix sum
        long long int sum = 0;
        for(int i = 0;i<n;i++) {
            // calculating prefix sum
            sum+=arr[i];
            // if sum becomes zero then theres an element which is making out sum to zero
            if(sum == 0)
            count++;
            // count all occurence of sum
            count+=mp[sum];
            // increment the frequency of element 
            mp[sum]++;
        }
        return count;
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
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends