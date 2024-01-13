/**
 * Definition of doubly linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node* ptr = head; Node* prev = NULL;
    while(ptr != NULL){
        if(ptr->data == k){
            Node* temp = ptr;
            ptr = ptr->next;
            temp->prev = NULL;
            temp->next = NULL;
            if(ptr != NULL){ //imp line
                ptr->prev = prev;
            }
            if(prev == NULL){
                head = ptr;
            }
            else{
                prev->next = ptr;
            }

            delete temp;
        }
        else{
            prev = ptr;
            ptr = ptr->next;
        }
    }

    return head;
}

//TC: O(n);
//SC: O(1);