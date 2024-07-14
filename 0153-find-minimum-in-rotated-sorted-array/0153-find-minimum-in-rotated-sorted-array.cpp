class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
        return nums[0];

        int s = 0, e = n - 1;
        int mid = s + (e - s)/2;
        int ans;
        bool ok = false;

        while(s <= e){

            if((mid + 1) <= e && nums[mid] > nums[mid + 1]){
                ans = nums[mid + 1];
                ok = true;
                break;
            }

            else if((mid - 1) >= s && nums[mid - 1] > nums[mid]){
                ans = nums[mid];
                ok = true;
                break;
            }

            else if(nums[s] > nums[mid])
            e = mid - 1;

            else
            s = mid + 1;

            mid = s + (e- s)/2;
            
        }

        if(ok)
        return ans;

        else
        return nums[0];
    }
};