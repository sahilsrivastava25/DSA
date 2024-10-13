class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        if(nums.size() == 0) return 0;

        unordered_set<int> st;
        for(int num: nums) st.insert(num);

        int longest = 1, len = 0;

        for(int num: st){
            if(st.find(num - 1) == st.end()){
                len = 1;
                int curr = num;

                while(st.find(curr + 1) != st.end()){
                    len++;
                    curr++;
                }

                longest = max(longest, len);
            }
        }
        return longest;
    }
};