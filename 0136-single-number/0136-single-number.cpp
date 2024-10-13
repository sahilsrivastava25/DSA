class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) ans = ans ^ nums[i];
        return ans;
    }
};