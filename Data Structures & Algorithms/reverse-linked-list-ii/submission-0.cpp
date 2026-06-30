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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* start = dummy;
        for(int i=1; i<left; i++){
            start = head;
            head = head->next;
        }
        ListNode* pres = head;
        ListNode* curr = head->next;
        for(int i=left; i<right; i++){
            // cout << pres->val << " " << curr->val << endl;
            ListNode* nex = curr->next;
            curr->next = pres; 
            pres = curr;
            curr = nex;
        }
        start->next = pres;
        head->next = curr;
        return dummy->next;
    }
};