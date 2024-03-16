//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    Node* reverse(Node *head) {
        Node *curr = head;
        Node *prev = NULL;
        Node *forward;
        while(curr) {
            forward = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
     l1= reverse (l1);
     l2= reverse (l2);
    Node* ans= new Node(0);
    Node* curr= ans;
    int sum=0; 
    while (l1 or l2 or sum){
             
    if (l1!= nullptr){
                 
    sum+= l1->data;
    l1= l1->next;
  }
             
    if (l2!= nullptr){
                 
    sum+= l2->data;
    l2= l2->next;
    }
        
  curr->next= new Node(sum%10);
   sum/=10;
   curr= curr->next; 
   }
          
  return reverse (ans->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends