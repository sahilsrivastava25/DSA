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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL) return head;

        int len = 1;
        ListNode* tail = head;

        while(tail->next){
            len++;
            tail = tail->next;
        }

        if(k % len == 0) return head;   
        k = k % len;

        tail->next = head;

        int cnt = len - k;
        ListNode* newLast = head;

        cnt--;
        while(cnt--) newLast = newLast->next;

        head = newLast->next;
        newLast->next = NULL;

        return head;
    }
};