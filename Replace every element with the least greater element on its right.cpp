//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    // optimal sol
    class Node{
        
        public :
        int data;
        Node * left;
        Node * right;
    
        
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
        
    };
    
    Node * insertNodeIntoBST_and_findItsSuccessorSimultaneously(Node * root , int key , Node * &suc){
        
        if(root==NULL) return  new Node(key);
        
        if( key < root->data){
            suc = root;
            root->left = insertNodeIntoBST_and_findItsSuccessorSimultaneously(root->left , key , suc);
        }
        else{
            root->right = insertNodeIntoBST_and_findItsSuccessorSimultaneously(root->right , key , suc);
        }
        
        return root;
        
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        
        Node * root = NULL;
        
        for(int i=n-1 ; i>=0 ; i--){
            Node * suc = NULL;
            root = insertNodeIntoBST_and_findItsSuccessorSimultaneously(root , arr[i] , suc);
            if(suc)
                arr[i] = suc->data;
            else
                arr[i] = -1;
        }
        
        return arr;
        
    }

    // brute force solution
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        
        // vector<int> ans;
        for(int i = 0;i<n;i++) {
            int maxi = INT_MAX;
            for(int j = i+1;j<n;j++) {
                if(arr[j] > arr[i] and maxi > arr[j])
                    maxi = arr[j];
            }
            if(maxi == INT_MAX)
            arr[i] = -1;
            else arr[i] = maxi;
        }
        return arr;
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
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends