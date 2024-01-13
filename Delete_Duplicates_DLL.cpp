/**
 * Definition of doubly linked list:
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

Node * removeDuplicates(Node *head)
{
    // Write your code here
    // Node* ptr = head;
    // while(ptr->next != NULL){
    //     if(ptr->data == ptr->next->data){
    //         Node* temp = ptr->next;
    //         ptr->next = temp->next;
    //         delete temp;
    //     }
    //     else{
    //         ptr = ptr->next;
    //     }
    // }
    // return head;

    Node* ptr = head;
    while(ptr->next != NULL){
        if(ptr->data == ptr->next->data){
            Node* temp = ptr->next;
            ptr->next = temp->next;
            if(temp->next){
                temp->next->prev = ptr;
            }
            temp->next = NULL; temp->prev = NULL;
            delete temp;
        }
        else{
            ptr = ptr->next;
        }
    }

    return head;
}

//TC: O(n);
//SC: O(1);