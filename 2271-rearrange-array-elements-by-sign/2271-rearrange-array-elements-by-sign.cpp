class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
    
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0)
            pos.push_back(nums[i]);
        }

        for(int i = 0; i < n; i++)
        {
            if(nums[i] < 0)
            neg.push_back(nums[i]);
        }

        int i = 0, j = 0;

        while(i < n/2  && j < n/2)
        {
            ans.push_back(pos[i]);
            i++;

            ans.push_back(neg[j]);
            j++;
        }

        return ans;
    }
};