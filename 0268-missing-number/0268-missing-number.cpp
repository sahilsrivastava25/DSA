class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int x1 = 0, x2 = 0;
        for(int i = 0; i < nums.size(); i++){
            x1 = x1 ^ nums[i];
            x2 = x2 ^ (i+1);
        }

        return (x1 ^ x2);
    }
};