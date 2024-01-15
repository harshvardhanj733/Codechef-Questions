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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* curr = head; ListNode* prev = NULL; ListNode* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head->next == NULL){
            return head;
        }
        ListNode* ptr = head;
        ListNode* start = head; ListNode* end = NULL; ListNode* prevEnd = NULL; ListNode* nextStart = NULL;
        int count = 0;
        while(ptr != NULL){
            count++;
            if(count == k){
                end = ptr;
                nextStart = end->next;
                end->next = NULL;
                if(prevEnd){
                    prevEnd->next = NULL;
                }
                end = reverse(start);
                if(prevEnd){
                    prevEnd->next = end;
                }
                prevEnd = start;
                start->next = nextStart;

                count = 0;
                if(head == start){
                    head = end;
                }
                ptr = start;
                start = start->next;
            }

            ptr = ptr->next;
        }

        return head;
    }
};

//TC: O(n*k);
//SC: O(1);