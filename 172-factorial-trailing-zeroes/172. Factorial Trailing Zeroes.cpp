class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0,prev=5;
        while (n/prev>0){
            // cout<<"at n="<<n<<", ans="<<ans<<", prev="<<prev<<endl;
            ans+=n/prev;
            prev*=5;
        }
        return ans;
    }
};