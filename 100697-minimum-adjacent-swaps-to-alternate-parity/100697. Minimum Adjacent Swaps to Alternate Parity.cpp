class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int c1 = 0, c2 = 0, n = nums.size();
        vector<int> oddPos, evenPos;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2) {
                ++c1;
                oddPos.push_back(i);
            } else {
                ++c2;
                evenPos.push_back(i);
            }
        }
        if (abs(c1 - c2) > 1) return -1;
        auto cost = [&](const vector<int>& pos, int start) {
            int cnt = 0;
            for (int k = 0; k < pos.size(); ++k) {
                cnt += abs(pos[k] - (start + 2*k));
            }
            return cnt;
        };
        if (c1 > c2) return (int)cost(oddPos, 0);
        if (c2 > c1) return (int)cost(evenPos, 0);
        return (int)min(cost(oddPos, 0), cost(evenPos, 0));
    }
};