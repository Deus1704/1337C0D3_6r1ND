class Solution {
public:
    int minSwaps(string s) {
        int n=s.size(), c1=0;
        vector<int>pos_1;
        for(int i=0; i<n; i++) if (s[i]-'0') { c1++; pos_1.push_back(i);}
        if (abs(n - 2*c1)>1) return -1;
        // try 010101...
        int swap1=0, miss0=0, miss1=0;
        for(int i=0; i<n; i++){
            if (i%2 == 0){
                // should've been a 0;
                miss0+= s[i]!='0';
            }else{
                // should've been a 1;
                miss1+= s[i]!='1';
            }
        }
        // cout<<"for swap1, m0="<<miss0<<", m1="<<miss1<<endl;
        // swap1 = max(miss0, miss1);
        if (miss0 != miss1) swap1 = 1e9;
        else swap1 = miss0;
        // try 101010...
        int swap2=0;
        miss0=0; miss1=0;
        for(int i=0; i<n; i++){
            if (i%2 == 0){
                // should've been a 1;
                miss1+= s[i]!='1';
            }else{
                // should've been a 0;
                miss0+= s[i]!='0';
            }
        }
        if (miss0 != miss1) swap2 = 1e9;
        else swap2 = miss0;
        // swap2 = max(miss0, miss1);
        // cout<<"for swap2, m0="<<miss0<<", m1="<<miss1<<endl;
        return min(swap1, swap2);
    }
};