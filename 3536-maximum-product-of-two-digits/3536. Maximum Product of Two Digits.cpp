class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int mc=0,smc=0;
        for (auto &i:s){
            cout<<"At i="<<i<<endl;
            if (smc<=(i-'0')){
                if (mc<(i-'0')){
                    smc = mc;
                    mc = (i-'0');
                }else{
                    smc = (i-'0');
                }
            }
            cout<<"SMC="<<smc<<" and mc="<<mc<<endl;
        }
        return smc*mc;
    }
};