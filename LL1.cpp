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
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr = head;
        int n = 0;
        while(ptr != NULL){
            n++;
            ptr = ptr->next;
        }
        ptr = head;
        int mid = n/2 + 1;
        for(int i = 0; i<mid-1; i++){
            ptr = ptr->next;
        }
        head = ptr;
        return head;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

// Approach: Brute Force Approach to Calculate the no of elements in the LL and subsequently iterate the pointer to the middle element.