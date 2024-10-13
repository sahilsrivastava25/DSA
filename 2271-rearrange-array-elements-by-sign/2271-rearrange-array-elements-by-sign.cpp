class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> ans(n);
        int pos = 0, neg = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};