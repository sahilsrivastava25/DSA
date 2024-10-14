class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int min = n/3;
        cout<<min;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && ele2 != nums[i]){
                 ele1 = nums[i];
                 cnt1 = 1;
            }
            else if(cnt2 == 0 && ele1 != nums[i]){
                 ele2 = nums[i];
                 cnt2 = 1;
            }
            else if(ele1 == nums[i]) cnt1++;
            else if(ele2 == nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < n; i++){
            if(ele1 == nums[i]) cnt1++;
            else if(ele2 == nums[i]) cnt2++;
        }

        if(cnt1 > min) ans.push_back(ele1);
        if(cnt2 > min) ans.push_back(ele2);

        return ans;
    }
};