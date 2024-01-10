/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {
    // Write your code here
    if(head == NULL || head->next == NULL){
        return 0;
    }

    Node* slow = head; Node* fast = head->next;
    while(fast != NULL && fast->next != NULL && slow != fast){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast == NULL || fast->next == NULL){
        return 0;
    }

    int count = 0;

    do{
        fast = fast->next;
        count++;
    }while(fast != slow);

    return count;
    
}

//TC: O(n);
//SC: O(1);