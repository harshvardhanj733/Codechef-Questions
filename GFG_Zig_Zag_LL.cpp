//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
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

class Solution
{
    private:
        Node* swap(Node* ptr1, Node* ptr2){
            Node* next = ptr2->next;
            ptr2->next = ptr1;
            ptr1->next = next;
            
            return ptr2;
        }
    public:
    Node *zigZag(Node* head)
    {
     // your code goes here
     
        if(head->next == NULL){
            return head;
        }
     
        Node* ptr = head;
        Node* prev = NULL;
        bool check = false;
        
        while(ptr->next != NULL){
            if(!check){
                if(ptr->data < ptr->next->data){
                    prev = ptr;
                    ptr = ptr->next;
                    check = true;
                }
                else{
                    ptr = swap(ptr, ptr->next);
                    if(prev == NULL){
                        head = ptr;
                    }
                    else{
                        prev->next = ptr;
                    }
                }
            }
            else{
                if(ptr->data > ptr->next->data){
                    prev = ptr;
                    ptr = ptr->next;
                    check = false;
                }
                else{
                    ptr = swap(ptr, ptr->next);
                    if(prev == NULL){
                        head = ptr;
                    }
                    else{
                        prev->next = ptr;
                    }
                }
            }
        }
        
        return head;
    }
};

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
		Node *ans = ob.zigZag(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends

//TC: O(n);
//SC: O(1);