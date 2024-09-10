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
    int gcd(int a, int b){
        if(a == 0) return b;
        return gcd(b % a, a);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        if(head->next == NULL) return head;

        ListNode* temp = head;
        
        while(temp && temp->next){
            int a = temp->val;
            int b = temp->next->val;

            ListNode* midNode = new ListNode();
            midNode->next = temp->next;
            temp->next = midNode;
            midNode->val = gcd(a,b);
            temp = temp->next->next;
        }
        return head;
    }
};