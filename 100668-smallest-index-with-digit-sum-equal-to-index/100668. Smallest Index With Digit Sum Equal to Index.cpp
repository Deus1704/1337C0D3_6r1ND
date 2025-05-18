class Solution {
    int summ(string s){
        int summm = 0;
        for (auto &i:s){
            summm+=i-'0';
        }
        return summm;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            if (summ(to_string(nums[i])) == i  ) return i;
        }
        return -1;
    }
};