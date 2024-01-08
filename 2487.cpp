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

    vector<bool> getNextGre(ListNode* t){
        vector<bool> v;
        ListNode* ptr = t;
        stack<int> st;

        while(ptr != NULL){
            while(!st.empty() && st.top() <= ptr->val){
                st.pop();
            }
            if(st.empty()){
                v.push_back(true);
            }
            else{
                v.push_back(false);
            }
            st.push(ptr->val);

            ptr = ptr->next;
        }
        reverse(v.begin(), v.end());
        return v;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* t = reverseLL(head);
        vector<bool> v = getNextGre(t);
        v.pop_back();
        ListNode* ptr = t;
        while(v.size() != 0 && ptr != NULL){
            if(!v[v.size() - 1]){
                ListNode* temp = ptr->next;
                ptr->next = temp->next;
                delete temp;
            }
            else{
                ptr = ptr->next;
            }
            v.pop_back();
        }

        ListNode* h = reverseLL(t);

        return h;
    }
};

//TC: O(n);
//SC: O(n);