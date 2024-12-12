class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int ptr=0;
        int len = nums.size();
        vector<int>result;
        for (int i=0; i<len; i++){
            ptr=(i+nums[i])%len;
            if (ptr<0) ptr+=len;
            result.push_back(nums[ptr]);
        }
        return result;
    }
};