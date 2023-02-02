// Linked List Insertion
// Create a link list of size N according to the given input literals. Each integer input is accompanied by an indicator which can either be 0 or 1. If it is 0, insert the integer in the beginning of the link list. If it is 1, insert the integer at the end of the link list. 
// Hint: When inserting at the end, make sure that you handle NULL explicitly.

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
  }  
  cout<<"\n";
} 



// } Driver Code Ends
/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) { // Time Complexity : O(1)
       // Your code here
       Node* ptr = (struct Node*)malloc(sizeof(struct Node));
       ptr->data = x;
       ptr->next = head;
       head = ptr;
       return head;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  { // Time Complexity : O(n)
       // Your code here
       Node* counter = head;
       Node* ptr = (struct Node*)malloc(sizeof(struct Node));
       ptr->data = x;
       if(counter == NULL){
           head = ptr;
           head->next = NULL;
       }
       else{
           while(counter->next != NULL){
               counter = counter->next;
           }
           counter->next = ptr;
           ptr->next = NULL;
       }
       return head;
    }
};

// Space Complexity : O(1);


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        struct Node *head = NULL;
        for (int i = 0; i < n; ++i)
        {
            int data, indicator;
            cin>>data;
            cin>>indicator;
            Solution obj;
            if(indicator)
                head = obj.insertAtEnd(head, data); 
            else
                head = obj.insertAtBegining(head, data);
        }
        printList(head); 
    }
    return 0; 
} 


// } Driver Code Ends