class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0, j=0, count=0, n=nums.size();
        while (j<n){
            while ( j<n && nums[j]-nums[i] <= k) j++;
            if (j<n && nums[j]-nums[i] > k) {
                i=j;
            }
            count++;
        }
        return count;
    }
};