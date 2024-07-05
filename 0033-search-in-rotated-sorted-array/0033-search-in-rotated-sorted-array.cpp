class Solution {
public:
    int bs(vector<int> nums, int s, int e, int target){
        int mid = s + (e-s)/2;
        while(s<=e){
            if(nums[mid] == target)
            return mid;

            else if(nums[mid]>target)
            e = mid - 1;

            else
            s = mid + 1;

            mid = s + (e-s)/2;
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int mid = s + (e-s)/2;
        int pivot;

        while(s <= e){
            if(s == e){
                pivot = s;
                break;
            }

            if((mid) <= e && nums[mid] > nums[mid+1]){
                pivot = mid;
                break;
            }

            if((mid-1)>=s && nums[mid-1] > nums[mid]){
                pivot = mid - 1;
                break;
            }

            if(nums[s] > nums[mid])
            e = mid - 1;

            else
            s = mid + 1;

            mid = s + (e-s)/2;
        }

        if(target >= nums[0] && target <= nums[pivot])
        return bs(nums, 0, pivot, target);

        else
        return bs(nums, pivot + 1, nums.size() - 1, target);
    }
};