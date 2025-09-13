class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int>vowels;
        map<char, int>consonants;
        set<char>vow = {'a', 'e', 'i', 'o', 'u'};
        for (auto &i:s){
            if (vow.find(i) != vow.end()){
                vowels[i]++;
            }else{
                consonants[i]++;
            }
        }
        int freq_vow=0; int freq_const=0;
        for (auto &i:vowels){
            if (i.second > freq_vow){
                freq_vow = i.second;
            }
        }
        for (auto &i:consonants){
            if (i.second > freq_const){
                freq_const = i.second;
            }
        }
        return freq_vow+freq_const;
        
    }
};