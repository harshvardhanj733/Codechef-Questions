/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* p1 = num1; 
    Node* p2 = num2;
    Node* prev = NULL;
    int carry = 0;
    
    while(p1 != NULL){
        int s1 = 0, s2 = 0;
        if(p1){s1 = p1->data;}
        if(p2){s2 = p2->data;}

        int sum = s1 + s2 + carry;
        int digit = sum%10; carry = sum/10;
        
        p1->data = digit;

        if(!p1->next && p2 && p2->next){
            prev = p1;
            p1->next = p2->next;
            p1 = p1->next;
            p2 = NULL;
        }
        else{
            prev = p1;
            p1 = p1->next;
            if(p2){p2 = p2->next;}
        }
    }

    if(carry > 0){
        Node* temp = new Node(1);
        prev->next = temp;
    }

    return num1;
}

//TC: O(n + m);
//SC: O(1);