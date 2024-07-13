class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);

        int n = nums.size();

        if(k == 0)
        return;

        k = k % n;

        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};