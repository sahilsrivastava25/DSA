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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        ListNode* dNode = new ListNode(-1);
        ListNode* temp = dNode;

        for(int i = 0; i < lists.size(); i++) 
        if(lists[i]) pq.push({lists[i]->val, lists[i]});

        while(!pq.empty()){
            pair<int, ListNode*> p = pq.top();
            temp->next = p.second;
            pq.pop();
            temp = temp->next;
            if(p.second->next) pq.push({p.second->next->val, p.second->next});
        }

        return dNode->next;
    }
};