class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int left_most_topx=-1,left_most_topy=-1, left_most_bottomx=-1, left_most_bottomy=-1, right_most_topx=-1, right_most_topy=-1, right_most_bottomx=-1, right_most_bottomy=-1;
        int mid_lefty = m, mid_righty=-1;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if(grid[i][j] && left_most_topx == -1){
                    left_most_topx = i; left_most_topy=j; break;
                }
                if (grid[i][j] && j<mid_lefty ){
                    mid_lefty = j;
                }
            }
        } // Now calc the left bottom
        for (int i=n-1; i>=0; i--){
            for (int j=0; j<m; j++){
                if(grid[i][j] && left_most_bottomx == -1){
                    left_most_bottomx = i; left_most_bottomy=j; break;
                }
            }
        }
        // Calc the right top
        for (int i=0; i<n; i++){
            for (int j=m-1; j>=0; j--){
                if(grid[i][j] &&  right_most_topx== -1){
                    right_most_topx = i; right_most_topy=j; break;
                }
                if (grid[i][j] && j>mid_righty){ mid_righty = j;}
            }
        }
        // Calculate the right bottom
        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                if(grid[i][j] && right_most_bottomx == -1){
                    right_most_bottomx= i; right_most_bottomy=j; break;
                }
            }
        }
        cout<<"LTx="<<left_most_topx<<", LTy="<<left_most_topy<<"\n";
        cout<<"LBx="<<left_most_bottomx<<", LBy="<<left_most_bottomy<<"\n";
        cout<<"RTx="<<right_most_topx<<", RTy="<<right_most_topy<<"\n";
        cout<<"RBx="<<right_most_bottomx<<", RBy="<<right_most_bottomy<<"\n";
        cout<<"Midleft="<<mid_lefty<<", mid_righty="<<mid_righty<<"\n";
        int width = max({right_most_topy, right_most_bottomy, mid_righty}) - min({left_most_topy, left_most_bottomy, mid_lefty}) +1;
        int height = max(right_most_bottomx, left_most_bottomx) - min(right_most_topx, left_most_topx) +1;
        cout<<"Got width="<<width<<", and ht="<<height<<endl;
        return width*height;
    }
};