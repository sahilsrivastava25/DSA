class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        sort(skill.begin(), skill.end());
        int n = skill.size();

        int totalsum = skill[0] + skill[n-1];
        long long ans = 0;

        for(int i = 0; i < n/2; i++){
            if(skill[i] + skill[n-i-1] != totalsum) return -1;
            ans += (long long)skill[i] * skill[n-i-1];
        }

        return ans;
    }
};