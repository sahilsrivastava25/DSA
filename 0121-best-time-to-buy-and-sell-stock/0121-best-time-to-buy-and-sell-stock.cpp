class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int maxProfit = 0;
        int minPrice = INT_MAX;

        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};