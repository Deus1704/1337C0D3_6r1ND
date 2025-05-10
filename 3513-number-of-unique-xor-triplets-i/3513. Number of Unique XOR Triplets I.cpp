class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n<3) return n;
        else{
            int tp = n; int count=0;
            while (tp>0){
                //keep right shifting till it reaches 0, thus counting its max set bit length.
                tp>>=1;
                count++;
            }
            return pow(2,count);
        }
    }
};