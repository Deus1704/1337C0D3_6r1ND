class Solution {
public:
    void rec(int index, int n, vector<string>&ans, string &s, int count){
        if (index==n){
            if (!count) {ans.push_back(s); return;}
            else return;
        }
        // put '('
        string temp = s; temp+='(';
        rec(index+1, n, ans, temp, count+1); 
        // put ')'
        string an = s; an+=')';
        if (count>0) rec(index+1, n, ans, an, count-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string base = "";
        rec(0, 2*n, ans, base, 0);
        return ans;
    }
};