class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        if(n <= 4)
        return 0;

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        //case1
        ans = min(ans, nums[n-4] - nums[0]);

        //case2
        ans = min(ans, nums[n-3] - nums[1]);

        //case3
        ans = min(ans, nums[n-2] - nums[2]);

        //case4
        ans = min(ans, nums[n-1] - nums[3]);

        return ans;
    }
};