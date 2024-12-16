class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for (auto &row:grid){
            for (auto &column:row){
                if (column<0) count++;
            }
        }
        return count;
    }
};