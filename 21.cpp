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

    ListNode* soln( ListNode* list1, ListNode* list2 ){
        ListNode* prev = list1;
        ListNode* next = list1->next;
        ListNode* curr = list2;

        while(curr != NULL){
            if(curr->val >= prev->val && (next == NULL || next->val >= curr->val)){
                ListNode* temp = curr;
                curr = curr->next;
                prev->next = temp;
                temp->next  = next;
                prev = prev->next;
            }
            else{
                prev = prev->next;
                next = next->next;
            }
        }

        return list1;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        else if(list1 == NULL){
            return list2;
        }
        else if(list2 == NULL){
            return list1;
        }

        if(list1->val <= list2->val){
            return soln(list1, list2);
        }

        return soln(list2, list1);
    }
};