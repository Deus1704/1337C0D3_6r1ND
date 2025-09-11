class Solution {
public:
    string sortVowels(string s) {
        set<char>st = {'a', 'e', 'i', 'o', 'u'};
        vector<char>to;
        for(auto &i:s){
            if ( st.count(tolower(i))) to.push_back(i);
        }
        sort(to.begin(), to.end());
        int ptr=0;
        for(int i=0; i<s.size(); i++){
            if ( st.count(tolower(s[i]))) {
                s[i] = to[ptr++];
            }
        }
        return s;
    }
};