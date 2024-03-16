//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    int maxStop(int n, int m, vector<vector<int>> &trains) {
        // code here
        vector<pair<int,int>> v;
        vector<int> plat(n+1, 0);
        
        for(int i = 0;i<trains.size();i++) {
            v.push_back({trains[i][1], i});
        }
        
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0;i<v.size();i++) {
            if(plat[trains[v[i].second][2]] <= trains[v[i].second][0]) {
                ans++;
                plat[trains[v[i].second][2]] = v[i].first;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> trains(m, vector<int>(3));
        Matrix::input(trains,m,3);
        
        Solution obj;
        int res = obj.maxStop(n, m, trains);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends