class Solution {
public:
    int maxLength(vector<int>& nums) {
        int l=0, r=1;
        int max_len = INT_MIN;
        int gcd_arr = 0, lcm_arr = 0;
        while (r<nums.size()){
            int prod = 1;
            vector<int>temp_arr;
            for (int i=l; i<=r; i++){
                prod *= nums[i];
                temp_arr.push_back(nums[i]);
            }
            gcd_arr = accumulate(temp_arr.begin(), temp_arr.end(), 0, [](int a, int b) {return std::gcd(a, b);});
            lcm_arr = accumulate(temp_arr.begin(), temp_arr.end(), 1, [](int a, int b) {return std::lcm(a, b);});
            cout<<"The temp_arr is="; for (auto &i:temp_arr) cout<<i<<" ";
            cout<<endl;
            cout<<"The prod="<<prod<<" & the gcd ="<<gcd_arr<<" and the lcm="<<lcm_arr<<endl;
            if (prod == lcm_arr*gcd_arr){
                max_len= max(max_len, r-l+1);
            }else if (prod > lcm_arr*gcd_arr){
                l++;
            }
            r++;
        }
        return max_len;
    }
};