class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        if(n <= 4)
        return 0;

        sort(nums.begin(), nums.end());

        int cas[4];

        //case1
        cas[0] = nums[n-4] - nums[0];

        //case2
        cas[1] = nums[n-3] - nums[1];

        //case3
        cas[2] = nums[n-2] - nums[2];

        //case4
        cas[3] = nums[n-1] - nums[3];

        int ans = *min_element(cas, cas + 4);

        return ans;
    }
};