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
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    Node* left = head;
    Node* right = head;
    while(right->next != NULL){
        right = right->next;
    }

    vector<pair<int, int>> res;
    while(left != right){
        if(left->data + right->data == k){
            res.push_back({left->data, right->data});
            left = left->next;
            if(left == right){
                return res;
            }
            right = right->prev;
        }
        else if(left->data + right->data < k){
            left = left->next;
        }
        else{
            right = right->prev;
        }
    }

    return res;
}

//TC: O(n);
//SC: O(1);