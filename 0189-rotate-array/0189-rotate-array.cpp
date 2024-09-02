class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int ro = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + ro);
        reverse(nums.begin() + ro, nums.end());
    }
};