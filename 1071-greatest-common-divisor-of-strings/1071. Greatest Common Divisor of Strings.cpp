class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2+str1) return "";
        else{
            int gcdlen = gcd(str1.size(), str2.size());
            return str1.substr(0,gcdlen);
        }
    }
};