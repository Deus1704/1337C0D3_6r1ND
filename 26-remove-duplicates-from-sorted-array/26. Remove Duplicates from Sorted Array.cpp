class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>hash_map;
        int k=0;
        for (int num:nums){
            hash_map[num]++;
        }
        for (auto& it:hash_map){
            if (it.second >= 1){
                nums[k] = it.first;
                k++;
            }
        }
        return k;
    }
};
// class Solution {
//  public:
//   int removeDuplicates(vector<int>& nums) {
//     int i = 0;

//     for (const int num : nums)
//       if (i < 1 || num > nums[i - 1])
//         nums[i++] = num;

//     return i;
//   }
// };