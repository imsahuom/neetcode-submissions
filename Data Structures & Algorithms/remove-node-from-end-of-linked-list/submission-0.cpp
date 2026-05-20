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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int t = 0;
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = head;
        while (curr){
            curr = curr->next;
            t++;
        }
        curr = dummy;
        t = t - n;
        while (t--){
            curr = curr->next;
        }
        ListNode* del = curr->next;
        curr->next = del->next;
        delete del;
        // cout << curr->val << endl;
        return dummy->next;
    }
};