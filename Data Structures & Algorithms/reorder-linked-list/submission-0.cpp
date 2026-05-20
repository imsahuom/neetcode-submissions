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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        stack<ListNode*> st; queue<ListNode*> q; int l = 0;
        ListNode* curr = head;
        while (curr){
            q.push(curr); st.push(curr); l++; curr = curr->next;
        }
        int n = l/2;
        ListNode* dummy = new ListNode(0);
        curr = dummy;
        while (n--){
            curr->next = q.front();
            curr = curr->next;
            curr->next = st.top();
            curr = curr->next;
            q.pop(); st.pop();
        }
        if (l%2 != 0){
            curr->next = q.front(); 
            curr = curr->next;
        }
        curr->next = nullptr;
        head = dummy->next;
        return;
    }
};