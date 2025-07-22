// Brute force -> Passes 20/63
// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         vector<int>middle;
//         int ptr=0, n=nums.size();
//         while (ptr<n){
//             while (ptr<n && nums[ptr] == 0) ptr++;
//             int count=ptr;
//             while (ptr<n && nums[ptr]==1) ptr++;
//             count = ptr - count;
//             middle.push_back(count);
//         }
//         // for (auto &i:middle) cout<<i<<","; cout<<endl;
//         int ans = 0;
//         if (middle[0] && middle[middle.size()-1]) {
//             for (int i=1; i<middle.size()-1; i++) if (middle[i]) ans+=middle[i];
//         }else{
//             int maxy = *max_element(middle.begin(), middle.end());
//             for (int i=0; i<middle.size(); i++){
//                 if (middle[i] && middle[i] != maxy) ans+=middle[i];
//             }
//         }
//         return ans;
//         // return 0;
//     }
// };

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int c1=0, n=nums.size(); for (auto &i:nums) if (i) c1++;
        // first the internal
        map<int,int>mp; for (int i=0; i<c1; i++) mp[nums[i]]++;
        int ans = mp[0]; // base ans; 
        for (int i=c1; i<n; i++){
            mp[nums[i-c1]]--; mp[nums[i]]++;
            ans = min(ans, mp[0]);
        }
        // cout<<"from the internal we got the min="<<ans<<endl;
        // now trying the circular shits
        map<int,int>rev; for (int i=0; i<c1-1; i++) rev[nums[i]]++; 
        rev[nums[n-1]]++;
        // cout<<"we took, array= ["; for (int i=0; i<c1-1; i++) cout<<nums[i]<<","; cout<<nums[n-1]<<endl;
        ans = min(ans, rev[0]);
        for (int i=1; i<c1; i++){
            rev[ nums[n-i-1] ]++; rev[nums[c1-i-1]]--;
// cout<<"we took, array= ["; for (int j=0; j<c1-i-1; j++) cout<<nums[j]<<","; for (int j=n-1; j>=n-i-1; j--) cout<<nums[j]<<","; 
//             cout<< "]"<<"while the 0 count=" << rev[0] <<endl;
            ans = min(ans, rev[0]);
        }
        return ans;
    }
};