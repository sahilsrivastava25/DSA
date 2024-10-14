class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int cnt = 0;
        int preSum = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            int rem = preSum - k;
            cnt += mp[rem];
            mp[preSum]++;
        }

        return cnt;
    }
};