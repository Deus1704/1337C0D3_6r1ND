class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        vector<int> result;
        for (auto it:nums1){
            mp1[it]++;
        }
        for (auto it:nums2){
            mp2[it]++;
        }
        for (auto& it:mp1){
            if (mp2.find(it.first) != mp2.end()){
                for (int i=0; i< min(it.second,mp2[it.first]); i++){
                    result.push_back(it.first);
                }
            }    
        }
        return result;
    }
};