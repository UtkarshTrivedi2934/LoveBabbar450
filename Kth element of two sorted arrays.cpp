//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:

    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m)return kthElement(arr2,arr1,m,n,k);
        int low=max(0,k-m),high=min(k,n);
        while(low<=high){
            int mid1=(low+high)>>1;
            int mid2=k-mid1;
            int l1=mid1==0?INT_MIN:arr1[mid1-1];
            int l2=mid2==0?INT_MIN:arr2[mid2-1];
            int r1=mid1==n?INT_MAX:arr1[mid1];
            int r2=mid2==m?INT_MAX:arr2[mid2];
            if(l1<=r2&&l2<=r1)return max(l1,l2);
            else if(l1>r2) high=mid1-1;
            else low= mid1 +1;
        }
        return 1;
    }

    int kthElement(int a[], int b[], int n, int m, int k)
   {
       int l=min(a[0],b[0]);
       int h=max(a[n-1],b[m-1]);
       while(l<=h){
           int mid=l+(h-l)/2;
           int x=upper_bound(a,a+n,mid)-a;
           int y=upper_bound(b,b+m,mid)-b;
           if(x+y<k) l=mid+1;
           else h=mid-1;
       }
       return l;
   }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends

   class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
int ptr1 = 0, ptr2=0;
        int check =0;
        while(ptr1 <n and ptr2 < m)
        {
            if(arr1[ptr1] < arr2[ptr2]){
                check++;
                if(check == k) return arr1[ptr1];
                ptr1++;
            }
            else{
                check++;
                if(check == k) return arr2[ptr2];
                ptr2++;
            }
        }
        while(ptr1 <n){
            check++;
            if(check == k) return arr1[ptr1];
            ptr1++;
        }
        while(ptr2 < m){
            check++;
            if(check == k) return arr2[ptr2];
            ptr2++;
        }
        return 1;
    }
};