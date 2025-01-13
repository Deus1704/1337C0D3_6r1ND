class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Way 1: looping over the k.
        // while (k--){
        //     int bot = nums[nums.size()-1]; nums.pop_back();nums.insert(nums.begin(), bot);
        // }

        // Way 2: Using extra vectors
        // if (k%nums.size()==0 ) return;
        // vector<int>back; back.assign(nums.begin()+ nums.size()-k, nums.end()); 
        // for (auto &i:back) cout<<i<<" "; cout<<endl;
        // nums.erase(nums.begin()+nums.size()-k, nums.end()); 
        // for (auto &i:nums) cout<<i<<" "; cout<<endl;
        // nums.insert(nums.begin(), back.begin(), back.end());
        
        // Way 3: Using reversing.
        if (k%nums.size()==0 ) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+(k%nums.size()));
        reverse(nums.begin()+k%nums.size(), nums.end());
    }
};