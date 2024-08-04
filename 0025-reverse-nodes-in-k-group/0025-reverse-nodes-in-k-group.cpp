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
    void reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev;
        ListNode* kNode;
        

        while(temp){
            kNode = temp;
            int cnt = k;

            cnt--;
            while(cnt-- && kNode)
            kNode = kNode->next;

            if(kNode == NULL){
                if(prev) prev->next = temp;
                break;
            }

            ListNode* next = kNode->next;
            kNode->next = NULL;
            reverse(temp);

            if(head == temp) head = kNode;
            else prev->next = kNode;

            prev = temp;
            temp = next;

        }
        return head;
    }
};