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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCPI = -1;
        int prevCPI = -1;
        int current = 1;

        vector<int> res(2);
        res[0] = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr->next != NULL){
            ListNode* nxt = curr->next;
            if((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val)){
                if(firstCPI == -1){
                    firstCPI = current;
                    prevCPI = current;
                }

                else{
                    res[0] = min(res[0],current - prevCPI);
                    prevCPI = current;
                }
            }
            prev = prev->next;
            curr = curr->next;
            current++;
        }

        if(firstCPI != -1 && res[0] != INT_MAX)
        res[1] = prevCPI - firstCPI;

        else{
            res[0] = -1;
            res[1] = -1;
        }

        return res;
    }
};