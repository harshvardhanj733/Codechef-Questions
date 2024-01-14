/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if(firstHead == NULL || secondHead == NULL){
        return NULL;
    }
    Node* ptr = firstHead;
    Node* tail = NULL;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    tail = ptr;
    tail->next = firstHead;

    //Find if loop exists
    Node* slow = secondHead; Node* fast = secondHead;
    do{
        fast = fast->next->next;
        slow = slow->next;
    }while(fast != NULL && fast->next != NULL && slow != fast);

    if(fast == NULL || fast->next == NULL){
        tail->next = NULL;
        return NULL;
    }

    slow = secondHead;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    
    tail->next = NULL;
    return slow;
}

//TC: O(n);
//SC: O(1);