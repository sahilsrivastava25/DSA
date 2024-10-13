class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        map<long long, int> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            long long sum = target - nums[i];

            if(mp.find(sum) != mp.end()) 
            {
                ans.push_back(i);
                ans.push_back(mp[sum]);
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};