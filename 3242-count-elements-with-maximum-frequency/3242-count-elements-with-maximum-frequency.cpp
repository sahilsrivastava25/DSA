class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp1;
        for(int i:nums)
        {
            mp1[i]++;
        }
        map<int,int>mp2;
        for(auto i:mp1)
          mp2[i.second]++;
        return mp2.rbegin()->first*mp2.rbegin()->second;
    }
};