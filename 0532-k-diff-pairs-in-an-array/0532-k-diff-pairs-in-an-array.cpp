class Solution {
public:

    int bs(vector<int>& nums, int s, int e, int target){
        int mid = s + (e-s)/2;

        while(s <= e){
            if(nums[mid] == target)
            return mid;

            else if(nums[mid] < target)
            s = mid + 1;
            
            else
            e = mid - 1;

            mid = s + (e - s)/2;
        }

        return INT_MIN;
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<pair<int, int>> ans;

        int i = 0, j = 1;

        for(int i = 0; i < n - 1; i++){
            int target = k + nums[i];

            int as = bs(nums, i + 1, n - 1, target);

            if(as == INT_MIN)
            continue;

            else
            ans.insert({nums[i], target});
        }

        return ans.size();

    }
};