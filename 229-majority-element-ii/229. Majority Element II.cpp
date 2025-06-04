class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size(),candidate1=0,candidate2=0 , count1=0, count2=0;
        // Moore's Voting Algo, slightly modified with a basic intuition.
        // any majority element, that has an occurence greater than n/3 would be at max 2.
        for (int i=0; i<n; i++){
            if (count1==0 && nums[i]!=candidate2){
                count1=1;candidate1=nums[i];
            }else if (count2==0 && nums[i]!=candidate1){
                count2=1;candidate2=nums[i];
            }else if (candidate1 == nums[i]) count1++;
            else if (candidate2 == nums[i]) count2++;
            else {count1--; count2--;}
        }
        // now verify if this candidate is actually the majority element;
        int dic1=0,dic2=0;
        for (auto &i:nums){
            if (i==candidate1) dic1++;
            else if (i==candidate2) dic2++;
        }
        cout<<"We have candiadtes1,2 -->"<<candidate1<<","<<candidate2;
        vector<int>ans;
        if (dic1>n/3) ans.push_back(candidate1);
        if (dic2>n/3) ans.push_back(candidate2);
        return ans;
    }
};

// -------------------- Following is the TC-> O(n*logn) and SC-> O(N) solution, this is the better
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n=nums.size(), k = floor(n/3);
//         unordered_map<int,int>mp;
//         for (int i=0; i<n; i++){
//             mp[nums[i]]++;
//         }
//         vector<int>ans;
//         for (auto &i:mp){
//             if (i.second>k){
//                 ans.push_back(i.first);
//             }
//         }
//         return ans;
//     }
// };