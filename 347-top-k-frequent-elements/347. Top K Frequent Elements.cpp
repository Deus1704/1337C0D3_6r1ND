class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        for (auto num : nums){
            hash_map[num]++;
        }
        vector<int> output;
        while(k--){
            int cur_max=-1;
            int cur_max_value =0;
            for (auto p : hash_map){
                if (p.second > cur_max){
                    cur_max = p.second;
                    cur_max_value = p.first;
                }
            }
            output.push_back(cur_max_value);
            hash_map.erase(cur_max_value);
        }
        return output;
    }
};
