class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int y = numBottles;
        int x = 0; //empty bottles
        int ans = 0;
        while(y){
            ans = ans + y;
            x = x + y;
            y = x / numExchange;
            x = x % numExchange;
        }

        return ans;
    }
};