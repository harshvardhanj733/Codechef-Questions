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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* ptr = head;
        int n = 0;
        while(ptr != NULL){
            n++;
            ptr = ptr->next;
        }

        k = k % n;
        if(k == 0){
            return head;
        }

        ptr = head;
        for(int i = 1; i < n-k; i++){
            ptr = ptr->next;
        }

        ListNode* head2 = ptr->next;
        ptr->next = NULL;

        ptr = head2;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = head;
        head = head2;

        return head;
    }
};

//TC: O(n);
//SC: O(1);