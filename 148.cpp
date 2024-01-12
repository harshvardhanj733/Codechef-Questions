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
    ListNode* findMid(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }

        ListNode* head = NULL; ListNode* ptr = NULL;
        while(left != NULL && right != NULL){
            ListNode* temp;
            if(left->val <= right->val){
                temp = left;
                left = left->next;
            }
            else{
                temp = right;
                right = right->next;
            }
            temp->next = NULL;
            if(head == NULL){
                head = temp;
                ptr = head;
            }
            else{
                ptr->next = temp;
                ptr = ptr->next;
            }
        }
        while(left != NULL){
            ListNode* temp = left;
            left = left->next;
            temp->next = NULL;
            if(head == NULL){
                head = temp;
                ptr = head;
            }
            else{
                ptr->next = temp;
                ptr = ptr->next;
            }
        }
        while(right != NULL){
            ListNode* temp = right;
            right = right->next;
            temp->next = NULL;
            if(head == NULL){
                head = temp;
                ptr = head;
            }
            else{
                ptr->next = temp;
                ptr = ptr->next;
            }
        }

        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);

        head = merge(left, right);
        return head;
    }
};

//TC: O(nlogn);
//SC: O(1);