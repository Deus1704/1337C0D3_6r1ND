class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int>ans;vector<int> pos;int n = nums.size();
        for (int i=0; i<n; i++) if (nums[i]==key) pos.push_back(i);
        for (auto &i:pos){
            int lef = i-k; while (lef<=i+k ) { if (lef>=0 && lef<n)ans.insert(lef); lef++;}
        }
        vector<int>an(ans.begin(),ans.end());
        return an;
    }
};