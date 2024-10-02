class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) mp[arr[i]] = 0;

        int rank = 1;
        for(auto val = mp.begin(); val != mp.end(); val++){
            val->second = rank;
            rank++;
        }

        vector<int> ans;
        for(int i = 0; i < arr.size(); i++) ans.push_back(mp[arr[i]]);

        return ans;
    }
};