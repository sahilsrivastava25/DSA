/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *a = head, *b = head;
        while (a != NULL and a->next != NULL) {
            a = a->next->next;
            b = b->next;

            if (a == b) {
                return true;
            }
        }
        return false;
    }
};