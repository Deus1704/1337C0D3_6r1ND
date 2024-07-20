class Solution {
public:
    int minimumLength(string s) {
        if (s.size()<=2) return s.size();
        unordered_map<char,int> mapp;
        for (auto ch:s){
            mapp[ch]++;
        }
        int Size = s.size();
        for (auto& it:mapp){
            if (it.second >= 3){
                int temp = (it.second-1)/2;
                Size-=2*temp;
            }
        }
        return Size;
    }
};