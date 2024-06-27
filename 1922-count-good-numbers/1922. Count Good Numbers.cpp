class Solution {
public:

    long long myPow(long long a, long long b, long long mod){
        long long result = 1;
        a = a % mod;
        while (b > 0) {
            if (b % 2 == 1) result = (result * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long mod = 1e9+7;
        if (n % 2 == 0){
            return static_cast<int>((myPow(5, n / 2, mod) * myPow(4, n / 2, mod)) % mod);
        } else {
            return static_cast<int>((myPow(5, (n + 1) / 2, mod) * myPow(4, (n - 1) / 2, mod)) % mod);
        }
    }
};