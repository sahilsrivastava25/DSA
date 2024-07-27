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
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;
        while(temp1 || temp2){
            int sum = 0;
            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;
            sum += carry;

            carry = sum / 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            curr->next = newNode;
            curr = newNode;
            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

        return dummy->next;
    }
};