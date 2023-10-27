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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* ptr = head;
        ListNode* prev = NULL;
        while(ptr != NULL && ptr->next != NULL){
            if(ptr->val == ptr->next->val){
                ListNode* temp = ptr;
                while(temp != NULL && temp->val == ptr->val){
                    temp = temp->next;
                }
                if(prev == NULL){
                    head = temp;
                }
                else{
                    prev->next = temp;
                }
                while(ptr != temp){
                    ListNode* toDelete = ptr;
                    ptr = ptr->next;
                    toDelete->next = NULL;
                    delete toDelete;
                }
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