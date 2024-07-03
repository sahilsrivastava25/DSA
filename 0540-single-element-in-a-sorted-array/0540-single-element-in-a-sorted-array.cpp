class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
        return 1;

        int s = 0, e = nums.size() - 1;
        int mid = s + (e-s)/2;
        int n = nums.size();
        int ans;

        while(s <= e)
        {   

            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid+1] && (mid - 1) >= 0 && (mid+1 ) < n)
            {
                ans = nums[mid];
                break;
            }

            else if(mid % 2 == 0)
            {
                if(nums[mid] == nums[mid-1]&& (mid - 1) >= 0)
                e = mid - 1;

                else if(nums[mid] == nums[mid + 1] && (mid+1) < n)
                s = mid + 1;
            }

            else if(mid % 2 != 0)
            {
                if(nums[mid] == nums[mid-1] && (mid - 1) >= 0)
                s = mid + 1;

                else if(nums[mid] == nums[mid + 1] && (mid+1 ) < n)
                e = mid - 1;
            }

            mid = s + (e-s)/2;

            if(mid == 0)
            return nums[0];

            else if(mid == n-1)
            return nums[n-1];
        }

        return ans;
    }
};