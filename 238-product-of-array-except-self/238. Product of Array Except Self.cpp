class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool is_prod_zero = false;
        int prod=1;
        for (auto i:nums){
            if (i){
                prod*=i;
            }else{
                is_prod_zero = true;
            }
        }
        int counts = count(nums.begin(),nums.end(), 0);
        if (counts>=2){
            vector<int>ans(nums.size());
            return ans;
        }else{
            for(auto &i:nums){
                if (is_prod_zero && i){
                    i=0;
                }else if (i){
                    i = (prod/i);
                }else{
                    i=prod;
                }
            }
        }
        return nums;
    }
};