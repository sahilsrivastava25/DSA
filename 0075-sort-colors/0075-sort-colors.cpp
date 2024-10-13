class Solution {
public:
    void sortColors(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int left = 0, mid = 0, right = nums.size() - 1;
        while(mid <= right){
            if(nums[mid] == 0){
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            }

            else if(nums[mid] == 1) mid++;

            else{
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};