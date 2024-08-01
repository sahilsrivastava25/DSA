class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char ,int> freq;

        for(auto it : s) freq[it]++;
        string ans="";

        for(auto it : order) {
            while(freq[it] > 0)
            {
            ans.push_back(it);
            freq[it]--;
            }
        }
        for(auto [it , fr] : freq){
            while(fr > 0) {
                ans.push_back(it);
                fr--;
            }
        }

        return ans;
    }
};