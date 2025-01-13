// SC=O(n) but using map ds
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         map<int,int>mp;
//         for (auto &i:nums) mp[i]++;
//         int ptr = nums.size()-1;
//         for (auto &x:mp){
//             for (auto &i:nums) cout<<i<<" "; cout<<endl;
//             while (x.second > 2){
//                 auto it = find(nums.begin(), nums.end(), x.first);
//                 // cout<<"The position to be swapped ="<<distance(nums.begin(), it)<<" &"<<ptr<<endl;
//                 swap(nums[distance(nums.begin(), it)], nums[ptr]);
//                 ptr--;
//                 x.second--;
//             }
//             // cout<<"The ptr="<<ptr<<endl;
//         }
//         sort(nums.begin(), nums.begin()+ptr+1);
//         for (auto &i:nums) cout<<i<<" "; cout<<endl;
//         return ptr+1;
//     }
// };

// SC= O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr=2;
        if (nums.size() <= 2) return nums.size();
        for (int i=2; i<nums.size(); i++){
            if (nums[i] != nums[ptr-2]){
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        return ptr;
    }
};