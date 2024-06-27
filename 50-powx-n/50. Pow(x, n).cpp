class Solution {
public:
    double myPow(double x, int n) {
        if (n&2 != 0){
            if (signbit(x)){
                return -1*exp(n*log(abs(x)));
            }
        }
        return exp(n*log(abs(x)));
    }
};