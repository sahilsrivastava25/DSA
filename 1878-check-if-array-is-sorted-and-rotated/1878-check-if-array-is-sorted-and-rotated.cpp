class Solution {
public:
    bool check(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int k;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                k = i;
                break;
            }
        }

        if(k == nums.size()) return true;

        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]) return false;
        }

        return true;
    }
};