class Solution {
public:
    string largestGoodInteger(string num) {
        set<string>s;
        int n = num.size();
        for (int i=0; i<n-2; i++){
            if (num[i] == num[i+1] && num[i+1]==num[i+2]){
                s.insert(num.substr(i,3));
            }
        }
        // cout<<*s.rbegin()<<endl;
        if (!s.size()) return "";
        return *s.rbegin();
    }
};