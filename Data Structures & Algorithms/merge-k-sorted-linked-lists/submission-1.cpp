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
struct cmp{
bool operator()(ListNode* a, ListNode* b){
    return a->val > b->val;
}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* dummy = new ListNode(-1); 
        ListNode* curr = dummy;
        priority_queue<ListNode*, vector<ListNode*>, cmp > pq;
        for(auto &l : lists){
            if (l){
                pq.push(l);
                l = l->next;
            }
        }
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            if (node->next) pq.push(node->next);
            curr->next = node;
            curr = curr->next;
        }
        return dummy->next;
    }
};