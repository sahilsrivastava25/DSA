class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0)
        return;

        int n =  nums.size();

        int temp[k];

        k = k % n;

        for(int i = n - k; i < n ; i++)
        temp[i+k-n] = nums[i];

        for(int i = n - k - 1; i >= 0; i--)
        nums[i+k] = nums[i];

        for(int i = 0; i < k; i++)
        nums[i] = temp[i];
    }
};