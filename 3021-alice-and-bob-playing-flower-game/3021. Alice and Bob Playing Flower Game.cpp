class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ecn = n/2, ocn = n-ecn, ecm = m/2, ocm = m-ecm;
        return (ecn*ocm) + (ocn*ecm);
    }
};