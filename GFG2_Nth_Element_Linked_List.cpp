// Nth node from end of linked list
// Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
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


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node * ptr = head;
       int count = 0;
       if(ptr == NULL){
           return -1;
       }
       while(ptr->next != NULL){
           ptr = ptr->next;
           count++;
       }
      count++;
       if(n>count){
           return -1;
       }
       ptr = head;
       for(int i = 0; i<count-n; i++){
           ptr = ptr->next;
       }
       return ptr->data;
       
}

// Time Complexity : O(N);
// Space Complexity: O(1);