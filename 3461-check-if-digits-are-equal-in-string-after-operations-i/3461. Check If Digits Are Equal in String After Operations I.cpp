class Solution {
public:
    bool hasSameDigits(string s) {
        int prev=0; int i=0; int n = s.size();
        vector<int> ints;
        while (i<s.size()){
            ints.push_back(s[i]-'0');
            i++;
        }
        while (ints.size() > 2){
            for (int i=0; i<n-1; i++){
                ints[i] = (ints[i]+ints[i+1])%10;
            }
            ints.pop_back();
        }
        // for (auto &i:ints) cout<<i<<",";
        // cout<<endl;
        return ints[0]==ints[1];
    }
};