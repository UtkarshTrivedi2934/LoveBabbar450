//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
    public:
    int data;
    Node *left;
    Node *right;
        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};

class cmp {
    public:
        bool operator()(Node *a,Node *b) {
            return a->data > b->data;
        }
};

class Solution
{
	public:
	    
	    void preorder(Node *root, vector<string> &ans, string temp)
	    {
	        if(!root)
	        return;
	        
	        if(!root->left and !root->right) {
	            ans.push_back(temp);
	            return;
	        }
	        preorder(root->left,ans,temp + "0");
	        preorder(root->right,ans,temp + "1");
	    }
	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Min heap to get the node with min freq
		    priority_queue<Node *, vector<Node *>, cmp> pq;
		    vector<string> ans;
		    
		    for(int i = 0;i<N;i++) {
		        Node *temp = new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    // pop the least freq node and merge it to get a new one
		    // repeat the task till node == 1
		    while(pq.size()!=1) {
		        Node *a = pq.top();
		        pq.pop();
		        
		        Node* b = pq.top();
		        pq.pop();
		        
		        Node *temp = new Node(a->data + b->data);
		        temp->left = a;
		        temp->right = b;
		        pq.push(temp);
		    }
		    // do the preorder to get desired codes
		    preorder(pq.top(),ans,"");
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends