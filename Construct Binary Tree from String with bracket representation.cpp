//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    
 Node* solver(string s, int start, int end) {
        if(start > end) return NULL;
        
        int i = start;
        while(i<=end && s[i]>='0' && s[i]<='9') {
            i++;
        }
        
        string front = s.substr(start, i-start);
        int num = stoi(front);
        Node* curr = new Node(num);
        if(i>=end) return curr;
        
        int pos = i, o = 0, c = 0;
        do{
            if(s[pos]=='(') o++; // 1
            if(s[pos]==')') c++; // 0
            pos++;
        } while(o!=c);
        

        curr->left = solver(s, i+1, pos-2);
        curr->right = solver(s, pos+1, end-1);
        return curr;
    }
    Node *treeFromString(string str){
        int n = str.length();
        return solver(str, 0, n-1);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends