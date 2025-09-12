class Solution {
public:
    bool doesAliceWin(string s) {
        int count_vowels=0; 
        set<char>vow = { 'a', 'e', 'i', 'o', 'u'};
        for(auto &i:s) if (vow.count(i)) count_vowels++;
        if (count_vowels > 0) return true;
        return false;
    }
};