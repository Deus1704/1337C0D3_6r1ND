bool cmp(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> temp;
        for (auto it : nums){
            int ans = 0;
            int divi = it;
            vector<int> digits;
            if (!divi) digits.push_back(divi);
            while (divi>0){
                digits.push_back(divi%10);
                divi /= 10; 
            }
            for (int i =digits.size()-1; i>=0; i--){
                ans = ans*10 + mapping[digits[i]];
            }
            temp.push_back({ans,it});
        }
        sort(temp.begin(),temp.end(), cmp);
        vector<int>finalans;
        for (auto& it:temp){
            finalans.push_back(it.second);
        }
        return finalans;
    }
};