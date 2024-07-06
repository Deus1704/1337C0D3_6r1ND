class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool possible = false;
        for (auto ch:ransomNote){
            auto t = magazine.find(ch);
            if (t!=string::npos){
                magazine.erase(t,1);
                possible = true;
            }
            else{
                possible = false;
                break;
            }
        }
        return possible;
    }
};