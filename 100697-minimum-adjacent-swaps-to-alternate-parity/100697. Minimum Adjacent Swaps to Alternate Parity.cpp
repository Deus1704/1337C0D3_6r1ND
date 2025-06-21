class Solution {
public:
    int cost_cal(vector<int> ar, int start){
        int cost=0;
        for (int k = 0; k < ar.size(); k++) {
            cost += abs(ar[k] -  (start+2*k));
        }
        return cost;
    }
    int minSwaps(vector<int>& nums) {
        int c1 = 0, c2 = 0, n = nums.size();
        vector<int> oddPos, evenPos;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2) {
                c1++;
                oddPos.push_back(i);
            } else {
                c2++;
                evenPos.push_back(i);
            }
        }
        if (abs(c1 - c2) > 1) return -1;
        int cost = 0;
        if (c1 > c2) {
            cost= cost_cal(oddPos, 0);
        }else if (c2>c1){
            cost = cost_cal(evenPos, 0);
        }else{
            cost = min(cost_cal(oddPos, 0), cost_cal(evenPos, 0));
        }
        return cost;
    }
};