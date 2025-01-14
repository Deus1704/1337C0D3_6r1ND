class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n=grid.size(), m= grid[0].size();
        vector<int> traversal;
        bool reached_last_in_prev = false;
        for (int i=0; i<n; i++){
            cout<<"Now prev_reached="<<reached_last_in_prev<<" at aray= ";
            for (auto &i:grid[i]) cout<<i<<" "; cout<<endl;
            if (i%2==0){ /// right traversal
                if (reached_last_in_prev){
                    for (int j=1; j<m;){
                        traversal.push_back(grid[i][j]);
                        if (j==m-1) reached_last_in_prev = true;
                        else reached_last_in_prev= false;
                        j+=2;
                    }
                }else{
                    for (int j=0; j<m;){
                        cout<<"ptr is here? and j="<<j<<endl;
                        traversal.push_back(grid[i][j]);
                        if (j==m-1) reached_last_in_prev = true;
                        else reached_last_in_prev= false;
                        j+=2;
                        cout<<"the prev flag at this= "<<reached_last_in_prev<<endl;
                    }
                }
            }// left traversal
            else{
                if (reached_last_in_prev){
                    for (int j=m-2; j>=0;){
                        traversal.push_back(grid[i][j]);
                        if (j==0) reached_last_in_prev = true;
                        else reached_last_in_prev= false;
                        j-=2;
                    }
                }else{
                    for (int j=m-1; j>=0;){
                        traversal.push_back(grid[i][j]);
                        if (j==0) reached_last_in_prev = true;
                        else reached_last_in_prev= false;
                        j-=2;
                    }
                }
            }
        }
        return traversal;
    }
};