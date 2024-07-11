class Solution {
public:
    string reverseParentheses(string& s) {
        stack<int>stac;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '('){
                stac.push(i);
                s.erase(s.begin()+i);
                i--;
            }else if(s[i]==')'){
                s.erase(s.begin()+i);
                auto left = stac.top();
                stac.pop();
                reverse(s.begin()+left, s.begin()+i);
                i--;
            }
        }
        return s;
    }
};