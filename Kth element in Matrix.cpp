//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];

//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



// A structure to store an entry of heap.  The entry contains
// a value from 2D array, row and column numbers of the value
struct module{
    int data;
    int x;
    int y;
    module(int data, int x, int y){
        this->data=data;
        this->x=x;
        this->y=y;
    }
};
    /*COMPARATOR CLASS.. NEEDED FOR HEAPIFYING*/

struct cmp{
    bool operator()(const module &M1, const module &M2){
        return M1.data>M2.data;
    }
};

int kthSmallest(int mat[MAX][MAX], int n, int k) {
     priority_queue<module,vector<module>,cmp> pq;
     for(int i=0;i<n;i++){
         pq.push(module(mat[i][0],i,0));
     }
     int res=0;
     for(int i=1;i<=k;i++){
         module curr=pq.top();
         pq.pop();
         
         res=curr.data;  //THREE ELEMENTS HARNESSED
         int currX=curr.x;
         int currY=curr.y;
         
         if(currY+1<n){
             pq.push(module(mat[currX][currY+1],currX,currY+1));
         }
     }
     return res;
}


int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  priority_queue<int> pq;
  for(int i = 0;i<n;i++) {
    for(int j = 0;j<n;j++) {
        pq.push(mat[i][j]);
    }
  }
  int rem = n*n-k;
  while(rem) {
      pq.pop();
      rem--;
  }
  return pq.top();
}
