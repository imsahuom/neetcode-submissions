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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while(curr){
            if (!curr->next) break;
            ListNode* nex = curr->next;
            int g = gcd(curr->val, nex->val);
            ListNode* node = new ListNode(g, nex);
            curr->next = node;
            curr = nex;
        }
        return head;
    }
};