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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode* curr1 = l1; ListNode* curr2 = l2; ListNode* tail1; ListNode* tail2;
        while (curr1 && curr2){
            sum = curr1->val + curr2->val + carry;
            curr1->val = sum%10; curr2->val = sum%10; 
            carry = sum/10;
            tail1 = curr1; tail2 = curr2;
            curr1 = curr1->next; 
            curr2 = curr2->next;
        }
        while(curr1){
            sum = curr1->val + carry;
            curr1->val = sum%10;
            carry = sum/10;
            tail1 = curr1;
            curr1 = curr1->next;
            if (!curr1 && carry){
                tail1->next = new ListNode(carry);
                return l1;
            }
        }
        int flag = 0;
        while (curr2){
            flag = 1;
            sum = curr2->val + carry; 
            curr2->val = sum%10; 
            carry = sum/10;
            tail2 = curr2;
            curr2 = curr2->next;
            if (!curr2 && carry){
                tail2->next = new ListNode(carry);
                return l2;
            }
        }
        if(!curr1 && !curr2 && carry){
            tail1->next = new ListNode(carry);
        }
        if (flag) return l2;
        return l1;
    }
};
