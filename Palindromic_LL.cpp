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
Node *reverseLL(Node *head) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* curr = head; Node* prev = NULL; Node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(Node *head)
{
    // write your code here
    if(head->next == NULL){
        return true;
    }
    Node* slow = head; Node* fast = head;
    while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* newList = reverseLL(slow->next);
    slow->next = NULL;

    Node* newPtr = newList; Node* ptr = head;
    while(newPtr != NULL){
        if(ptr->data != newPtr->data){
            newList = reverseLL(newList);
            slow->next = newList;
            return false;
        }
        newPtr = newPtr->next;
        ptr = ptr->next;
    }

    newList = reverseLL(newList);
    slow->next = newList;
    return true;
}

//TC: O(n);
//SC: O(1);