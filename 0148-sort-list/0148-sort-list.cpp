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

    ListNode* findMid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* t1, ListNode* t2){
        ListNode* dNode = new ListNode(-1);
        ListNode* curr = dNode;

        while(t1 && t2){
            if(t1->val < t2->val){
                curr->next = t1;
                curr = t1;
                t1 = t1->next;
            }

            else{
                curr->next = t2;
                curr = t2;
                t2 = t2->next;
            }
        }
        if(t1) curr->next = t1;
        else curr->next = t2;

        return dNode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* middle = findMid(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = NULL;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return merge(leftHead, rightHead);
    }
};