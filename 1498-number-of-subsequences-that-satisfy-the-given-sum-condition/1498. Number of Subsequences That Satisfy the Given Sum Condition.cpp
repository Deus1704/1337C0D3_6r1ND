class Solution {
public:
    int modpow(int base, int exp, int mod){
        base = base%mod;
        int result=1; 
        while (exp){
            if (exp&1){
                result = int((1LL * result * base) % mod);
            }
            base = int((1LL * base   * base) % mod);
            exp/=2;
        }
        return result%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9+7;
        int n= nums.size(), left=0, right = n-1;
        int ans=0;
        // int two_ki_4 = modpow(2,42,mod);
        // cout<<two_ki_4<<endl;
        while (left<=right){
            if (nums[left]+nums[right]<=target){
                ans = (ans%mod+(modpow(2,right-left, mod))%mod)%mod;
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};