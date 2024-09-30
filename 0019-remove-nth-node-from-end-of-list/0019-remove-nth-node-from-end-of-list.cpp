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
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        ListNode* fast = head;
        ListNode* slow = head;
        
        for(int i = 1; i <= n; i++) fast = fast->next;

         if(fast == NULL){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        

        ListNode* delNode = slow->next;

        slow->next = slow->next->next;

        delete delNode;

        return head;
    }
};