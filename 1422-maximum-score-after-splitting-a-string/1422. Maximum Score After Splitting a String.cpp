class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(),s.end(), '1');
        int max_score = INT_MIN;
        int zeros = 0;
        for (int i=0; i<s.size()-1; i++){
            if (s[i]=='0'){
                zeros++;
            }else{
                ones--;
            }
            max_score = max(max_score , zeros+ones);
        }
        return max_score;
    }
};