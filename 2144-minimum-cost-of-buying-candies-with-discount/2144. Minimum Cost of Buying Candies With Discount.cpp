class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int minCost = 0;
        int count = 0;
        sort(cost.rbegin(),cost.rend());
        for (int i = 0; i<cost.size(); i++){
            count++;
            if (count>2){
                count = 0;
            }else{
                minCost+=cost[i];
            }
        }
        return minCost;
    }
};