//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:

 int median(vector<vector<int>> &matrix, int r, int c){
      
      int start_val = 0,end_val = 2000;
      
      while(start_val <= end_val)
      {
         int centre_val = (start_val + end_val)/2;
         int count=0;
         int n = r*c;
         for(int i=0;i<r;i++)
         {
             int l=0,h=c-1;
             while(l<=h)
             {
                   int mid = l + (h-l)/2;
                   
                   if(matrix[i][mid] <= centre_val)
                   l = mid+1;
                   
                   else
                   h = mid-1;
             }
             count = count + l;
         }
         
         if( count > n/2 )
           end_val = centre_val-1;
         else
           start_val = centre_val+1;
      }
      
      return start_val;
   }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends