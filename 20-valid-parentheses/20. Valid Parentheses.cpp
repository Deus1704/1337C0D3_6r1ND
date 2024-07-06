class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string op = "([{";
        string ed = ")]}";
        for (auto stri:s){
            if (op.find(stri) != string::npos) st.push(stri);
            else if (ed.find(stri) != string::npos){
                if ( st.empty() || ed.find(stri) != op.find(st.top())) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};