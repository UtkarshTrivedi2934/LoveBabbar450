//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    void nslnsr(vector<int>&arr , vector<int>&heights , int n , string s)
    {
        stack<int>st;
        if(s == "nsl")
        {
            for(int i=0;i<n;i++)
            {
                while(!st.empty() && heights[i] <= heights[st.top()])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    arr[i] = st.top();
                }
                st.push(i);
            }
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                while(!st.empty() && heights[i] <= heights[st.top()])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    arr[i] = st.top();
                }
                st.push(i);
            }
        }
    }
    
    int max_area_of_hist(vector<int>&arr , int size)
    {
        vector<int>left(size,-1);
        vector<int>right(size,size);
        nslnsr(left , arr , size , "nsl");
        nslnsr(right , arr , size , "nsr");
        
        int ans = arr[0];
        for(int i=0;i<size;i++)
        {
            ans = max(ans , (right[i] - left[i] - 1)*arr[i]);
        }
        return ans;
    }
  
    int maxArea(int matrix[MAX][MAX], int n, int m)
    {
        int maxarea = 0;
        vector<int>update(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    update[j] = 0;
                }
                else
                {
                    update[j] += matrix[i][j];
                }
            }
            maxarea = max(maxarea , max_area_of_hist(update , m));
        }
        return maxarea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends