class Solution {
public:
    bool isPowerOfTwo(int n) {
        // int count_set_bits = 0; 
        // if (n<0) return false;
        // while (n){
        //     if (n&1) count_set_bits++;
        //     n>>=1;
        // }
        // if (count_set_bits==1) return true;
        // else return false;
        return ( n>0 && (n&(n-1)) ==0);
    }
};