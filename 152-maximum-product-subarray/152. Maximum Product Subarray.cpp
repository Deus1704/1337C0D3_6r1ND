class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Brute Force
        int maxy=-1e9, n=nums.size();
        for (int i=0; i<n; i++){
            int prod = nums[i];
            maxy= max(maxy, prod); // Sirf individual
            for (int j=i+1; j<n; j++){
                prod*=nums[j];
                maxy= max(maxy, prod);
            }
        }
        return maxy;
    }
};