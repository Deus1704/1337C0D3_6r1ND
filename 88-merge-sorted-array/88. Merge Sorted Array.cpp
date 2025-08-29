class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=0,r=0; vector<int>ans; 
        while (l<m && r<n){
            if (nums1[l] > nums2[r]){
                ans.push_back(nums2[r]); r++;
            }else{
                ans.push_back(nums1[l]); l++;
            }
        }if (l<m) for (int i=l; i<m; i++) ans.push_back(nums1[i]);
        if (r<n) for (int i=r; i<n; i++) ans.push_back(nums2[i]);
        nums1 = ans;
    }
};