class Solution {
public:
    int minimumLength(string s) {
        int len = 0;
        map<char,int>mp;
        for (auto &i:s) mp[i]++;
        for (auto &i:mp){
            if (i.second < 2) len+=i.second;
            else {
                len+= i.second%2==0?2:1;
            }
        }
        return len;
    }
};