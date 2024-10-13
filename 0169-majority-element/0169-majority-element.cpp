class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el = nums[0];

        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(el == nums[i]) cnt++;
            else cnt--;
        }
        return el;
    }
};