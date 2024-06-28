class Solution {
public:
    int myAtoi(string s) {
        bool isNeg = false;
        bool firstNonZeroHit = false;
        long long ans = 0;
        int i=0;
        while(i < s.length() && s[i] == ' ') i++;
        if(i == s.length()) return 0;
        if (i < s.length() && (s[i]=='-'||s[i]=='+')){
            isNeg = (s[i]=='-');
            i++;
        }
        while(i<s.length() && (s[i]>= '0' && s[i]<='9')){
            ans = ans*10 + (s[i]-'0');
            if (!isNeg && ans >INT_MAX) return INT_MAX;
            if (isNeg && -ans < INT_MIN) return INT_MIN;
            i++;
        }
        return static_cast<int>(isNeg ? -ans : ans);
    }
};