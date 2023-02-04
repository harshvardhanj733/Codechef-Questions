// Remove duplicates from an unsorted linked list
// Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     int arr[10001];
     for(int i = 0; i<10001; i++){
         arr[i] = -1;
     }
     Node * ptr = head->next;
     Node * prev = head;
     arr[head->data]++;
     while(ptr!=NULL){
         if(arr[ptr->data] == -1){
             arr[ptr->data]++;
             prev = ptr;
             ptr = ptr->next;
         }
         else{
             Node * rmv = ptr;
             prev->next = ptr->next;
             ptr = ptr->next;
             free(rmv);
         }
     }
     return head;
    }
};

// Time Complexity : O(N);
// Space Complexity : O(N);


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends