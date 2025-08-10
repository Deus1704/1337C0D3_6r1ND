class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size(); vector<int>temp;
        for (int i=0; i<n; i++){
            if (nums[i] != i){
                temp.push_back(nums[i]);
            }
        }
        if (temp.size()){
            int start = temp[0];
            for (int i=1; i<temp.size(); i++) start&=temp[i];
            return start;
        }return 0;
    }
};