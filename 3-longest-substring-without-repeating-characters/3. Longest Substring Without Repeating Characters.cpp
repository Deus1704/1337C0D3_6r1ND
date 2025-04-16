#include <set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ptr1=0; int ptr2=0;
        unordered_set<char> se;
        int len = 0;
        while (ptr2<s.size() && ptr2>=ptr1){
            if (se.find(s[ptr2]) != se.end()){
                // se.clear();
                while (s[ptr1] != s[ptr2]){
                    se.erase(s[ptr1]);
                    ptr1++;
                }
                se.insert(s[ptr2]);
                ptr1++;
            }else{
                se.insert(s[ptr2]);
                len = max(len, (int)se.size());
            }
            // cout<<"The ptr2="<<ptr2<<", and the ptr1="<<ptr1<<"The elements of se=";
            // for (auto &i:se) cout<<i<<", ";
            // cout<<endl;
            ptr2++;
        }
        return len;
    }
};