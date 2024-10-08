class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        ListNode* curr=head;
        int n=0;
        while(curr){
            curr=curr->next;
            n++;
        }
        auto [q, r]=div(n, k);
       
        vector<int> iLen(k, q);
        fill(iLen.begin(), iLen.begin()+r, q+1);//Use fill
        vector<ListNode*> ans(k);
        curr=head;
        for(int i=0; i<k; i++){
            ans[i]=curr;
            for (int j=0; j < iLen[i]-1; j++) {
                curr=curr->next;
            }
            if (curr) { //Check if curr is not null
                ListNode* prev=curr; //extra pointer is needed
                curr=curr->next;
                prev->next=NULL; //Remove the link
            }
        }
        return ans;
    }
};