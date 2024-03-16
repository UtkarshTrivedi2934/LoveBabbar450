//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    int findPos(int in[],int &ele,int s,int e) {
    for(int i = s;i<=e;i++) {
        if(in[i] == ele)
        return i;
    }
    return -1;
}

Node *solve(int in[],int pre[],int &index,int start,int end,int size) {
    if(index>=size or start > end) 
    return NULL;

    int ele = pre[index++];
    Node *root = new Node(ele);
    int position = -1; 
    position = findPos(in,ele,start,end);

    root->left = solve(in,pre,index,start,position-1,size);
    root->right = solve(in,pre,index,position+1,end,size);
    return root;
}

    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        return solve(in,pre,preOrderIndex,0,n-1,n);
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
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends