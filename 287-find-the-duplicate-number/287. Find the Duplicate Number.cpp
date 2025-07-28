class Solution {
public:
    // int findDuplicate(vector<int>& nums) {
    //     int ptr=0, n=nums.size();
    //     for (int i=0; i<n; i++){
    //         if (nums[abs(nums[i])] <0 ){
    //             // found the repeated number
    //             ptr = i;
    //             break;
    //             // return abs(nums[abs(nums[i])]);
    //         }else{
    //             nums[abs(nums[i])] *= -1;
    //         }
    //     }
    //     for (auto &i:nums) if (i<0) i*=-1;
    //     return nums[ptr];
    // }
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0], slow = nums[0]; bool first = true;
        while (slow != fast || first){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (first) first = false;
        }
        // we are gaurantee to find a cycle since PHP suggests that since there are n+1 holes and n types 
        // of items so one of the holes would have an item same as 1-n 
        
        // Now reset the slow to start; The fast is still inside the loop
        slow = nums[0];
        // now keep moving, till the fast and slow meet
        while (fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};