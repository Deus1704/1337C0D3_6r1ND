class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singlesum = 0, doublesum = 0;
        for (auto it : nums){
            if (it>=10){
                doublesum+=it;
            }else{
                singlesum+=it;
            }
        }
        if (singlesum>doublesum || doublesum>singlesum) return true;
        return false;
    }
};