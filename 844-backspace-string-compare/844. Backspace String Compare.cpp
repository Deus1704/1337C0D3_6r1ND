class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> set1;
        stack<char> set2;
        for (char ch : s){
            if (ch == '#'){
                if (!set1.empty()){
                    set1.pop();
                }
            }else{
                set1.push(ch);
            }
        }
        for (char c : t){
            if (c == '#'){
                if (!set2.empty()){
                    set2.pop();
                }
            }else{
                set2.push(c);
            }
        }
        while(!set1.empty() && !set2.empty()){
            if (set1.top()!=set2.top()){
                return false;
            }
            set1.pop();
            set2.pop();
        }
        return set1.empty() && set2.empty();
    }
};