// class Solution {
// public:
//     int modpow(long long base, long long exp, long long MOD){
//         base %= MOD;
//         long long result = 1;
//         while (exp){
//             if (exp&1) result = (result*base)%MOD;
//             base=(base*base)%MOD;
//             exp/=2;
//         }return result%MOD;
//     }
//     vector<int> productQueries(int n, vector<vector<int>>& queries) {
//         // int x = floor(log2(n+1));
//         long long MOD = 1000000007LL;
//         vector<int>ans, binary;
//         vector<long long> temp;
//         while (n){
//             binary.push_back(n%2);
//             n/=2;
//         }
//         for (int i=0; i<binary.size(); i++){
//             if (binary[i]) temp.push_back(modpow(2,i, MOD));
//         }
//         // for (auto &i:temp) cout<<i<<","; cout<<endl;
//         vector<long long>prefix_prod(temp.size()+1,1); for(int i=1; i<=temp.size(); i++) {prefix_prod[i] = ((temp[i-1])*(prefix_prod[i-1]))%MOD;}
//         for (auto &i:queries){
//             int start = i[0], end = i[1];
//             ans.push_back((prefix_prod[end+1]/prefix_prod[start]));
//         }
//         return ans;
//     }
// };
class Solution {
public:
    long long modpow(long long base, long long exp, long long MOD){
        base %= MOD;
        long long result = 1;
        while (exp){
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const long long MOD = 1000000007LL;
        vector<int> ans, binary;
        vector<long long> temp;
        while (n){
            binary.push_back(n % 2);
            n /= 2;
        }
        for (int i = 0; i < (int)binary.size(); ++i) {
            if (binary[i]) temp.push_back(modpow(2, i, MOD));
        }
        vector<long long> prefix_prod(temp.size() + 1, 1);
        for (int i = 1; i <= (int)temp.size(); ++i) {
            prefix_prod[i] = (prefix_prod[i - 1] * temp[i - 1]) % MOD;
        }

        // answer queries using modular inverse for division
        for (auto &q : queries) {
            int start = q[0], end = q[1];
            long long numerator = prefix_prod[end + 1];
            long long denominator = prefix_prod[start];
            long long inv_den = modpow(denominator, MOD - 2, MOD); // Fermat inverse, MOD is prime
            long long res = (numerator * inv_den) % MOD;
            ans.push_back((int)res);
        }
        return ans;
    }
};
