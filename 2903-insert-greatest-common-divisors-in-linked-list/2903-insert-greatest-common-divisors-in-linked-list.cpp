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
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        if(head->next == NULL) return head;

        ListNode* temp = head;
        
        while(temp && temp->next){
            ListNode* midNode = new ListNode();
            midNode->val = gcd(temp->val, temp->next->val);
            midNode->next = temp->next;
            temp->next = midNode;
            temp = temp->next->next;
        }
        return head;
    }
};