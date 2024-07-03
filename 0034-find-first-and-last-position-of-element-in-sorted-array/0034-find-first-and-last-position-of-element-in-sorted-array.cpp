class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans(2 , -1);

        if(binary_search(nums.begin(), nums.end(), target) == 0)
        return ans;

        //first occurrence
        int s = 0, e = nums.size() - 1;
        int mid = s + (e-s) / 2;
        int first, last;

        while(s <= e){
            if(nums[mid] == target){
                first = mid;
                e = mid - 1;
            }

            else if(nums[mid] > target)
            e = mid - 1;

            else
            s = mid + 1;

            mid = s + (e-s)/2;
        }

        ans[0] = first;

        //last occurnce
        s = 0, e = nums.size() - 1;
        mid = s + (e-s)/2;

        while(s <= e){
            if(nums[mid] == target){
                last = mid;
                s = mid + 1;
            }

            else if(nums[mid] > target)
            e = mid - 1;

            else
            s = mid + 1;

            mid = s + (e-s)/2;
        }

        ans[1] = last;

        return ans;

    }
}; 