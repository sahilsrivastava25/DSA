class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        if(target < nums[0])
        return 0;
        
        int s = 0, e = nums.size() - 1;
        int mid = s + (e-s)/2;
        int index;


        
        while(s <= e){
            if(nums[mid] == target)
            return mid;

            else if(nums[mid] > target)
            e = mid - 1;

            else{
                index = mid;
                s = mid + 1;
            }

            mid = s + (e-s)/2;
        }

        return (index + 1);
    }
};