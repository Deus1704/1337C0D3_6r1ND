class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans;ans.push_back({1});
        for (int i=1; i<=rowIndex; i++){
            vector<int>prev = ans[i-1]; vector<int>cur; cur.push_back(1);
            for (int j=0; j<prev.size()-1; j++){
                cur.push_back(prev[j]+prev[j+1]);
            }
            cur.push_back(1); ans.push_back(cur);
        }
        return ans[rowIndex];
    }
};