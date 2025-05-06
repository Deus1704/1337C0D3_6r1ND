class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Simple Prefix sums concept
        int count =0;
        map<int, int>sums_hash; sums_hash[0]=1;
        int temp_sum =0; 
        for (auto &i:nums){
            temp_sum+=i;
            if (sums_hash.count(temp_sum-k)){
                count+=sums_hash[temp_sum-k];
            }    
            sums_hash[temp_sum]++;
        }
        // if k+some_element = cur_sum in the prefix array then that would be a valid case
        // Like for example;
        // array = {3,1,5,2,4} and k = 6
        // now prefix sum array= {3,4,9,11,15}
        // at the position 2, if cur_sum=9, and the k=6, then 
        // check if there exists a cur_sum-k in the prefix sums array, if it exists then add that to the count.
        return count;
    }
};