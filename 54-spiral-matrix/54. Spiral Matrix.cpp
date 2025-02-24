class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<vector<int>>visited(matrix.size(),vector<int>(matrix[0].size()));
        int a=0,b=matrix[0].size()-1,c=matrix.size()-1,d=0;
        while (a>=0 && b>=0 && c>=0 && d>=0){
            // move right
            for (int i=d; i<=b; i++){
                if (visited[a][i]==0) {ans.push_back(matrix[a][i]); visited[a][i]++;}
            }a++;
            // move down
            for (int i=a; i<=c; i++){
                if (visited[i][b]==0) {ans.push_back(matrix[i][b]); visited[i][b]++;}
            }b--;
            // move left
            for (int i=b; i>=d; i--){
                if (visited[c][i]==0) {ans.push_back(matrix[c][i]); visited[c][i]++;}
            }c--;
            // move up
            for (int i=c; i>=a; i--){
                if (visited[i][d]==0) {ans.push_back(matrix[i][d]); visited[i][d]++;}
            }d++;
            // cout<<"At this point, a="<<a<<", b="<<b<<", c="<<c<<" and d="<<d<<endl;
        }
        return ans;
    }
};