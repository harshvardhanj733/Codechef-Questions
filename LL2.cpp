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
    bool hasCycle(ListNode *head) {
        if (head == NULL){
            return false;
        }
        else if(head->next == NULL){
            return false;
        }
        else{
            ListNode* ptr = head;
            for(int i = 0; i<10000; i++){
                ptr = ptr->next;
                if(ptr == NULL){
                    return false;
                }
            }
            return true;
        }
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)

// Approach: If there is a circular LL, then we won't reach the NULL pointer anytime. So, I ran a for loop for 10000 times as this was the limit given in the question. This way, if we found a NULL node, then return false, otherwise, after 10000 iterations, return true.
// Hence, it takes constant time and constant space.