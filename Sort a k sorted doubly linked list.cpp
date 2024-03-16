//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class DLLNodeComparator {
public:
    bool operator() (const DLLNode *node1, const DLLNode *node2) {
        return node1->data > node2->data;
    }
};

class Solution
{
public:
    
    DLLNode *sortAKSortedDLL(DLLNode *head, int k)
    {
        // code here
        if(!head)
        return NULL;
        
        priority_queue <DLLNode*, vector<DLLNode*>, DLLNodeComparator> pq;        DLLNode *newHead = NULL;
        
        DLLNode *p = head;
        
        for(int i = 0; p != NULL and i<=k; i++) {
            pq.push(p);
            p = p->next;
        }
        DLLNode *curr;
        while(!pq.empty()) {
            if(newHead == NULL) {
                newHead = pq.top();
                newHead->prev = NULL;
                curr = newHead;
            }
            else {
                curr->next = pq.top();
                pq.top()->prev = curr;
                curr = pq.top();

            }
            
            pq.pop();
            
            if(p) {
                pq.push(p);
                p = p->next;
            }
        }
        curr->next = NULL;
        return newHead;
    }
};

//{ Driver Code Starts.

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data)
{
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head)
{
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a;
        cin >> a;
        DLLNode *head = new DLLNode(a);
        DLLNode *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            push(&tail, a);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends