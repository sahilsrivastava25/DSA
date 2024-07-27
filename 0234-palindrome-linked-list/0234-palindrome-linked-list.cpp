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

    ListNode* reverse(ListNode* node){

        if(node == NULL || node->next == NULL) return node;
        ListNode* prev = NULL;
        ListNode* temp = node;

        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        while(second){
            if(first->val != second->val){
                reverse(newHead);
                return false;
            }
            second = second->next;
            first = first->next;
        }

        reverse(newHead);
        return true;
    }
};