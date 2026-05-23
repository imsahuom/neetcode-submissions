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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;ListNode* prev = nullptr;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = nxt;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1); dummy->next = head;
        ListNode* curr = dummy; 
        while(curr->next){
            int cnt = 0;
            ListNode* oldhead = curr->next; ListNode* nxt = curr->next; ListNode* last;
            while(nxt){
                // cout << nxt->val << " ";
                cnt++;
                last = nxt;
                nxt = nxt->next;
                if(cnt == k) break;
            }
            // cout << "= " << cnt << " \n";
            if (cnt >= k){
                last->next = nullptr;
                ListNode* newhead = reverse(oldhead);
                curr->next = newhead;
                oldhead->next = nxt;
                curr = oldhead;
            }else{
                break;
            }
        }
        return dummy->next;
    }
};
