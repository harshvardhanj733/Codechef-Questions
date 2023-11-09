/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        ListNode* end = tail;

        ListNode* ptr = head;
        ListNode* prev = NULL;
        while(prev != tail){
            if(ptr->val >= x){
                if(ptr == end){
                    prev = ptr;
                    ptr = ptr->next;
                    continue;
                }
                if(prev != NULL){
                    prev->next = ptr->next;
                }
                else{
                    head = ptr->next;
                }
                ListNode* node = ptr;
                if(node == tail){
                    tail = prev;
                }
                ptr = ptr->next;
                node->next = NULL;
                end->next = node;
                end = end->next;
                
            }
            else{
                prev = ptr;
                ptr = ptr->next;
            }
        }

        return head;
    }
};

//TC: O(n);
//SC: O(1);