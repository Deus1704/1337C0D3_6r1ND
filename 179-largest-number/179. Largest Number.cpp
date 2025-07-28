class Solution {
public:
    void rec(int index, vector<string>&temp, vector<string>&ans, int n){
        if (index == n){
            // ans.push_back(temp);
            string s = ""; for (auto &i:temp) s+=i; ans.push_back(s);
            return;
        }
        for (int i=0; i<n; i++){
            swap(temp[index], temp[i]);
            rec(index+1, temp, ans, n);
            swap(temp[i], temp[index]);
        }
    }
    // A recursive Solution which generates all the possible combinations of the array and 
    // then returns the max
    // string largestNumber(vector<int>& nums) {
    //     vector<string>temp;
    //     int n = nums.size();
    //     for (auto &num:nums){
    //         temp.push_back(to_string(num));
    //     }
    //     vector<string>all_poss;
    //     rec(0, temp, all_poss, n);
    //     sort(all_poss.rbegin(), all_poss.rend());
    //     // for (auto &i:all_poss) cout<<i<<","; cout<<endl;
    //     return all_poss[0];
    // }
    string largestNumber(vector<int>& nums) {
        vector<string>temp; for (auto &num:nums) temp.push_back(to_string(num));
        sort(temp.begin(), temp.end(), [&](string t1, string t2){
            return t1+t2 > t2+t1;
        });
        string ans="";
        for (auto &i:temp) ans+=i;
        int zero_count = 0; for (auto &i:ans) if (i-'0' == 0) zero_count++;
        if (zero_count == ans.size()) return "0";
        return ans;
    }
};