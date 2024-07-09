class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        long long product = 1;
        bool zeroDetected = false;
        bool nonZeroPresent = false;
        int countZero = 0;
        for (auto num: nums){
            if (num){
                product *= num;
                nonZeroPresent = true;
            }else{
                zeroDetected = true;
                countZero++;
            }
        }
        for (int i=0; i<nums.size(); i++){
            if (zeroDetected){
                if (nums[i]){
                    answer.push_back(0);
                }else{
                    if (!nonZeroPresent || countZero >1){
                        answer.push_back(0);
                    }else{
                        answer.push_back(product);
                    }
                }
            }else{
                answer.push_back(product/nums[i]);
            }
        }
        return answer;
    }
};