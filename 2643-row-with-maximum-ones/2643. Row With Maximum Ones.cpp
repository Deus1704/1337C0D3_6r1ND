class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans;
        int m= mat.size(), n = mat[0].size(), max = 0, idx=0;
        for (int i=0; i<m; i++){
            int co=0;
            for (int j=0; j<n; j++){
                if (mat[i][j]) co++;
            }
            if (co>max){ max = co; idx = i;}
        }
        return {idx, max};
    }
};