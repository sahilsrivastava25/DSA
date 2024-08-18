class Solution {
public:
    const int xmin=-5*1e4;
    vector<int> bucket[64];//64**3=262144>1e5+1
    void radix_sort(vector<int>& nums) {
        // 1st round
        for (int& x : nums){// adjust x-=xmin
            x-=xmin;
            bucket[x&63].push_back(x);
        }
        int i = 0;
        for (auto &B : bucket) {
            for (auto v : B)
                nums[i++] = v;
            B.clear();
        }
        // 2nd round
        for (int& x : nums)
            bucket[(x>>6)&63].push_back(x);
        i=0;
        for (auto &B : bucket) {
            for (auto v : B)
                nums[i++] = v;
            B.clear();
        }
        // 3rd round
        for (int& x : nums)
            bucket[x>>12].push_back(x);
        i=0;
        for (auto &B : bucket) {
            for (auto v : B)//adjust back
                nums[i++] = v+xmin;
        //    B.clear();
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        radix_sort(nums);
        return nums;
    }
};




auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}(); 