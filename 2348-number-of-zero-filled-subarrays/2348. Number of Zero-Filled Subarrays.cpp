class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0; int n = nums.size();
        // Count individual zeros and the runs-1
        long long ptr=0;
        while (ptr<n){
            long long start = ptr;
            while (ptr<n && nums[ptr] == 0){
                ans++; ptr++;
            }
            if (ptr - start > 1) {
                ans+= ((ptr - start - 1)*(ptr - start))/2;
            } 
            // cout<<"Ans = "<<ans<<", and ptr="<<ptr<<endl;
            ptr++;
        }
        return ans;
    }
};