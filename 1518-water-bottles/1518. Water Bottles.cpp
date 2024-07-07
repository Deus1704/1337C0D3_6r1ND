class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int filled = numBottles;
        int empty = 0;
        int ans =0;
        bool canContinue = true;
        while (canContinue){
            ans += filled;
            empty += filled;
            filled = empty/numExchange;
            empty -= filled*numExchange;
            if (!filled) {
                canContinue = false;
            }
        }
        return ans;
    }
};