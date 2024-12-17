class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        cout<<"reached here?"<<endl;
        if (m==1 && n==1) return matrix[m-1][n-1]==target;
        int l=0,r=m-1;
        while (l<=r){
            int mid = (l+r)/2;
            cout<<"mid is="<<mid<<" and at ="<<matrix[mid][n-1]<<endl;
            if (matrix[mid][n-1]<target){
                l=mid+1;
            }else if (matrix[mid][n-1]>target){
                r=mid-1;
            }else{
                return true;
            }
        }
        cout<<"Found l="<<l<<endl;
        if (l>m-1){return false;}
        int l2=0,r2=n;
        while (l2<=r2){
            int mid = (l2+r2)/2;
            cout<<"mid is at = "<<mid<<"the value is = "<<matrix[l][mid]<<endl;
            if (matrix[l][mid]<target){
                l2=mid+1;
            }else if(matrix[l][mid]>target){
                r2=mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};
