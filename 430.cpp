/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* getFlat(Node* & head){
        if(head == NULL){
            return NULL;
        }

        Node* curr = head;
        Node* prev = head;

        while(curr != NULL){
            if(curr->child == NULL){
                prev = curr;
                curr = curr->next;
            }
            else if(curr->child != NULL){
                Node* next = curr->next;
                Node* child = curr->child;
                curr->next = child;
                child->prev = curr;
                curr->child = NULL;
                Node* flatEnd = getFlat(child);
                prev = flatEnd;
                prev->next = next;
                if(next != NULL){
                    next->prev = prev;
                }
                curr = next;
            }
        }
        return prev;
    }

    Node* flatten(Node* head) {
        if(head == NULL){
            return NULL;
        }

        Node* res = getFlat(head);
        return head;
    }
};

//TC: O(n);
//SC: O(1);