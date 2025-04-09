class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int miny=INT_MAX;
        for (auto &i:nums) {
            if (i<=miny){
                miny = i;
            }
        }
        if (miny>=k){
            // this is where the case of minimum >= k is to be handled
            sort(nums.rbegin(), nums.rend());
            int decs = 0;
            for (int i=0; i<nums.size()-1; i++){
                if (nums[i]>nums[i+1]) decs++;
            }
            if (k==miny){
                return decs;
            }else{
                return decs+1;
            }
        }else{
            return -1;
        }
    }
};