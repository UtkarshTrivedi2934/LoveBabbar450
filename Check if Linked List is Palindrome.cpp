//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(!head or !head->next)
        return true;
        // FInd middle element of LL
        Node *slow = head;
        Node* fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse after middle position
        // if OG ll were 1 2 3 4 5
        // now its 1 2 3 5 4
        Node *curr = slow;
        Node* prev = NULL;
        Node* forward;
        
        while(curr) {
            forward = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = forward;
        }
        fast = head;
        
        // check if last's data equals to first's data
        while(prev) {
            if(fast->data != prev->data)
            return false;
            fast = fast->next;
            prev = prev->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends