// This cannot be solved with Greedy

class Solution {
public:
    bool rec(int l , int r, int suma, int sumb, int parity, vector<int>&piles){
        // base case;
        if (l == r-1){
            if (parity){
                // i.e B's turn
                return sumb+max(piles[l], piles[r]) < suma+min(piles[l], piles[r]);
            }else{
                return suma+max(piles[l], piles[r]) > sumb+min(piles[l], piles[r]);
            }
        }
        // for the current parity person try to get the optimal way;
        // pick first
        bool first = rec(l+1, r, suma+ (parity==0? piles[l]:0), sumb+ (parity==1? piles[l]:0), parity^1, piles);
        bool last = rec(l, r-1, suma + (parity==0? piles[r]:0), sumb+ (parity==1? piles[r]:0) , parity^1, piles);
        return first||last;
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size(), l=0, r=n-1;
        // return rec(l,r,0, 0, 0,piles);
        return true;
    }
};