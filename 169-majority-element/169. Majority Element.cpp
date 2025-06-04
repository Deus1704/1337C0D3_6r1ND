class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(),candidate=0, count=0;
        for (int i=0; i<n; i++){
            if (count==0){
                candidate = nums[i];
                count=1;
            }
            else if (nums[i]==candidate){
                count++;
            }else{
                count--;
            }
        }
        // now verify if this candidate is actually the majority element;
        int dic=0;
        for (auto &i:nums) if (i==candidate) dic++;
        if (dic>n/2) return candidate;
        else return -1;
    }
};