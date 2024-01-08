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
    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL; ListNode* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    vector<int> nextLarge(ListNode* head){
        vector<int> v; stack<int> st;
        ListNode* ptr = head;
        while(ptr != NULL){
            while(!st.empty() && st.top() <= ptr->val){
                st.pop();
            }
            if(st.empty()){
                v.push_back(0);
            }
            else{
                v.push_back(st.top());
            }

            st.push(ptr->val);
            ptr = ptr->next;
        }

        reverse(v.begin(), v.end());
        return v;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        head = reverseLL(head);
        vector<int> v = nextLarge(head);
        head = reverseLL(head);

        return v;   
    }
};

//TC: O(n);
//SC: O(n);