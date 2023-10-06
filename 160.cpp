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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tail = headA;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = headA;

        ListNode* slow = headB; ListNode* fast = headB;

        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }

            if(slow != NULL && slow == fast){
                break;
            }
        }

        if(fast == NULL){
            tail->next = NULL;
            return NULL;
        }

        slow = headB;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        tail->next = NULL;
        return slow;
    }
};

//Time Complexity: O(n+m);
//Space Complexity: O(1);