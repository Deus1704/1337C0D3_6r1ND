class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();sort(nums.begin(),nums.end());
        // for (auto &i:nums)cout<<i<<","; cout<<endl;
        set<vector<int>>s;
        for (int i=0; i<n-2; i++){
            // if (i>0 && nums[i]==nums[i-1])continue;
            int l=i+1,r=n-1;
            // cout<<"Now starting with,i="<<i<<",l="<<l<<",r="<<r<<endl;
            while (l<r){
                int summ = nums[i]+nums[l]+nums[r];
                // cout<<"summ="<<summ<<endl;
                if (summ>0){
                    r--;
                }else if (summ<0){
                    l++;
                }else{
                    s.insert({nums[i],nums[l],nums[r]});
                    // break;
                    l++;r--;
                }
            }
            // cout<<"Now ending with,i="<<i<<",l="<<l<<",r="<<r<<endl;
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};
// --------------- Appreciate the single handedly implementing this, but still its O(n^3);
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n= nums.size();
//         set<vector<int>>temp;
//         set<pair<pair<int,int>,int>>pos_sum;
//         for (int i=0; i<n-1; i++){
//             for (int j=i+1; j<n; j++){
//                 pos_sum.insert({{i,j},nums[i]+nums[j]});
//             }
//         }
//         for (auto &it:pos_sum){
//             cout<<"at, i="<<it.first.first<<",j="<<it.first.second<<", summ="<<it.second<<endl;
//         }
//         for (int k=0; k<n; k++){
//             for (auto &tp:pos_sum){
//                 // const auto [[i,j],sum] = tp;
//                 int i = tp.first.first,j=tp.first.second,summ = tp.second;
//                 if (k!=i && k!=j && nums[k]+summ==0){
//                     vector<int>dd = {nums[i],nums[j],nums[k]};sort(dd.begin(),dd.end());
//                     temp.insert(dd);
//                 }
//             }
//         }
//         vector<vector<int>>ans(temp.begin(),temp.end());
//         return ans;
//     }
// };