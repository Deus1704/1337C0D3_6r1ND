class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count=0,left=0, right=0;
        while (left < g.size() && right<s.size()){
            while ( (left < g.size() && right<s.size()) && g[left] > s[right]) right++;
            if ( (left < g.size() && right<s.size()) &&  g[left] <= s[right]) {
                count++; left++; right++;
            }
        }
        return count;
    }
};