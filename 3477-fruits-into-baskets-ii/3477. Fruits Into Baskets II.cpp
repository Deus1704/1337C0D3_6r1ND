class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size(), ptr=0;
        vector<int>used_basket(n,0);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (baskets[j] >= fruits[i] && !used_basket[j]) { ptr++; used_basket[j]=1; break;}
            }
        }
        return n-ptr;
    }
};