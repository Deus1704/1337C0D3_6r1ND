class FindSumPairs {
public:
    vector<int>n1,n2;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1; n2=nums2;
        for (auto &i:n2) mp[i]++;
    }
    
    void add(int index, int val) {
        mp[n2[index]]--; if (mp[n2[index]]==0) mp.erase(n2[index]);
        n2[index]+=val;
        mp[n2[index]]++;
    }
    
    int count(int tot) {
        int c=0;
        for (auto &i:n1){
            if (mp[tot-i]>0) c+=mp[tot-i];
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */