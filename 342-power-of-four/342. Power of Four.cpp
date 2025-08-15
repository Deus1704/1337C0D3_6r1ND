class Solution {
public:
    bool isPowerOfFour(int n) {
        // cout<<(0x00000003 & n)<<endl;
        // return  n>0 && ( (0x00000003 & n) ==0 || n==1 );
        if (n<=0) return false;
        while (n>1){
            if (n%4!=0) return false;
            n/=4;
        }
        return true;
    }
};