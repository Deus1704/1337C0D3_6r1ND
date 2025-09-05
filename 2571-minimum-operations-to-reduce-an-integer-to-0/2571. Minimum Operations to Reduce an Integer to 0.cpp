class Solution {
public:
    int minOperations(int n) {
        // string bin=""; int temp=n;
        // while(temp){
        //     bin+= to_string(temp%2); temp>>=1;
        // }reverse(bin.begin(), bin.end());
        // for(auto &i:bin) cout<<i<<""; cout<<endl;
        int ops=0;
        // while(ptr>=0){
        //     while (ptr && bin[ptr] == '0') ptr--;
        //     int start = ptr;
        //     while( ptr && bin[ptr] == '1'){
        //         bin[ptr]='0'; ptr--;
        //     }
        //     bool flag = false;
        //     if (ptr - start > 1){
        //         if (ptr>=0) bin[ptr]='1';
        //         else bin.insert(bin.begin(),'1'); flag = true;
        //         ops++;
        //     }
        //     if(!flag) ptr--;
        // }
        // for(auto &i:bin) { cout<<i<<""; if (i=='1') ops++;}
        // return ops;

        // Much easier Greedy solution;
        for(int i=0; i<=18; i++){
            if (__builtin_popcount( n + (1<<i)  ) < __builtin_popcount(n) ){
                n+= ( 1<<i ); ops++;
            }
        }
        return ops+__builtin_popcount(n);
    }
};