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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left == right){
            return head;
        }

        int count = 1;
        ListNode* curr = head;
        ListNode* prevHead = NULL;
        ListNode* nextHead = NULL;

        for(count = 1; count < left; count++){
            prevHead = curr;
            curr = curr->next;
        }

        ListNode* prev = NULL;
        ListNode* next = NULL;

        nextHead = curr;
        for(count = left; count <= right; count++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if(prevHead != NULL){
            prevHead->next = prev;
        }
        nextHead->next = next;

        if(left == 1){
            head = prev;
        }

        return head;
    }
};

//Time Complexity: O(n);
//Space Complexity: O(1);