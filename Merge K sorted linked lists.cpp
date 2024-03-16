//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
     Node * mergeKLists(Node *arr[], int k)
    {
        
        Node* head=new Node(-1),*t;
        t=head;
        int i;
        
      priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>q;
      pair<int,Node*> nd;
      for(i=0;i<k;i++)
          q.push({arr[i]->data,arr[i]});
      
      
      while(!q.empty())
      {
          nd=q.top();
          q.pop();
          
          t->next=new Node(nd.first);
          t=t->next;
          if(nd.second->next!=0)
          {
              q.push({nd.second->next->data,nd.second->next});
          }
          
      }
         return head->next;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends