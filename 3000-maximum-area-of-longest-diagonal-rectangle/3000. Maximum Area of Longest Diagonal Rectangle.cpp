class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxy_diag = 0, max_area= 0, n=dimensions.size();
        for (int i=0; i<n; i++){
            int dist = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1];
            if (dist >= maxy_diag){
                maxy_diag = dist;
            }
        }
        for(int i=0; i<n; i++){
            if (dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1] == maxy_diag){
                max_area = max( max_area, dimensions[i][0]*dimensions[i][1]);
            }
        }
        return max_area;
    }
};