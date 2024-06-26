class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ptr1 = 0;
        int ptr2 = 0;
        int max_len = 0;
        set<char> st;
        while (ptr2< s.size()){
            if (st.find(s[ptr2]) == st.end()){
                st.insert(s[ptr2]);
                max_len = max(max_len, ptr2 - ptr1 +1);
                ptr2++;
            }else {
                st.erase(s[ptr1]);
                ptr1++;
            }
        }
        return max_len;
    }
};