class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ptr1 =0;
        int ptr2 = numbers.size()-1;
        while (ptr1 != ptr2){
            int cs = numbers[ptr1]+numbers[ptr2];
            if (cs > target){
                ptr2--;
            }else if (cs<target){
                ptr1++;
            }
            else{
                return {ptr1+1, ptr2+1};
            }
        }
        return {};
        
    }
};