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

    int traversal(ListNode* & head){
        if(head == NULL){
            return 0;
        }
        if(head->next == NULL){
            return 1;
        }

        int count = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL){
            count++;
            curr = curr->next;
        }
        return count;
    }

    ListNode* addNums(ListNode* & l1, ListNode* & l2){
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int carry = 0;

        while(ptr1 != NULL){
            int sum = 0;
            sum += ptr1->val;
            if(ptr2 != NULL){
                sum += ptr2->val;
            }
            sum += carry;

            int digit = sum%10;
            carry = sum/10;

            ptr1->val = digit;
            
            if(ptr1->next == NULL && carry != 0){
                ListNode* temp = new ListNode(carry);
                ptr1->next = temp;
                carry = 0;
            }

            ptr1 = ptr1->next;
            if(ptr2 != NULL){
                ptr2 = ptr2->next;
            }
        }
        return l1;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = traversal(l1);
        int len2 = traversal(l2);



        if(len1 >= len2){
            return addNums(l1, l2);
        }
        return addNums(l2, l1);
    }
};

//Time Complexity: O(n);
//Space Complexity: O(1);