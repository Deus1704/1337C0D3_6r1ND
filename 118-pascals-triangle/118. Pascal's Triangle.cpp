class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        int index = 2;
        numRows-=1;
        while (numRows--){
            vector<int> temp(index);temp[0]=1;temp[index-1]=1;
            for (int i=1; i<index-1; i++){
                temp[i] = ans[index-2][i] + ans[index-2][i-1];
            }
            index++;
            ans.push_back(temp);
        }
        return ans;
    }
};