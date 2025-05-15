class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<string>ans;
        for (int i=0; i<n; i++){
            vector<string>temp;temp.push_back(words[i]);
            for (int j=i+1; j<n; j++){
                if (groups[j]!=groups[j-1]){
                    temp.push_back(words[j]);
                }
            }
            if (temp.size()>ans.size()){
                ans.clear();
                for (auto &i:temp){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};