class Solution {
public:
    int possibleStringCount(string word) {
        unordered_map<char, int> mp;
        for (int i=0; i<word.size()-1; i++){
            // mp[c]++;
            if (word[i]==word[i+1]){
                mp[word[i]]++;
            }
        }
        int possible_strings = 1;
        for (auto it : mp){
            if (it.second >=1){possible_strings += it.second;}
        }
        return possible_strings;
    }
};