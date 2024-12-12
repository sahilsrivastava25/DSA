class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
        // Create max-heap
        make_heap(g.begin(), g.end());
        for (int i = 0, x = INT_MAX; i < k && x > 1; i++) {
            // Pop max element
            pop_heap(g.begin(), g.end());
            x = g.back();
            // Update element
            g.back() = sqrt(g.back());
            push_heap(g.begin(), g.end());
        }
        // Return sum
        return accumulate(g.begin(), g.end(), 0LL);
    }
};
        