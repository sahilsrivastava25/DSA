class Solution {
public:
    static int minGroups(vector<vector<int>>& intervals) {
        const int n=intervals.size();
        vector<int> P;
        P.reserve(n*2);
        for(auto& I: intervals){
            int x=I[0], y=I[1]+1;
            P.push_back((x<<1)+1);
            P.push_back(y<<1);
        }
        sort(P.begin(), P.end());
        int cnt=0, x=0;
        for(int z: P){
            x+=(z&1)?1:-1;
            cnt=max(cnt, x);
        }
        
        return cnt;    
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();