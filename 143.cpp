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
private:
    ListNode* reverse(ListNode* midPlusOne){
        if(midPlusOne == NULL || midPlusOne->next == NULL){
            return midPlusOne;
        }

        ListNode* curr = midPlusOne;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    int numNodes(ListNode* head){
        int count = 0;
        ListNode* ptr = head;
        while(ptr != NULL){
            count++;
            ptr = ptr->next;
        }

        return count;
    }

public:
    void reorderList(ListNode* head) {
        int n = numNodes(head);
        int mid = n/2 + 1;

        ListNode* ptr = head;
        for(int i = 1; i < mid; i++){
            ptr = ptr->next;
        }

        ListNode* midPlusOne = ptr->next;
        ptr->next = NULL;

        ListNode* last = reverse(midPlusOne);
        ptr = head;

        ListNode* ptrLast = last;

        while(ptrLast != NULL){
            ListNode* temp = ptrLast;
            ptrLast = ptrLast->next;
            ListNode* temp2 = ptr->next;
            ptr->next = temp;
            temp->next = temp2;
            ptr = temp2;
        }
    }
};

//TC: O(n)
//SC: O(1)