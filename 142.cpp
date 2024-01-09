/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //check if loop exists
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* slow = head; ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL && slow != fast){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == NULL || fast->next == NULL){
            return NULL;
        }

        if(slow == head){
            return slow;
        }
        slow = head;
        fast = fast->next;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

//TC: O(n);
//SC: O(1);