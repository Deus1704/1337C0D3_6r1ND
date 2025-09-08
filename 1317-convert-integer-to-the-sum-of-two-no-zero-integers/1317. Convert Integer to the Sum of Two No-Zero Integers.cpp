class Solution {
public:
    bool check(int n){
        string t=to_string(n); 
        for(auto &i:t) if (i=='0') return false;
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        // string t = to_string(n), a="", b=""; int carry= 0;
        // for(int i=t.size()-1; i>=0; i--){
        //     int to_add = t[i]-'0' ;
        //     if (to_add == 0){
        //         to_add = 10; carry++;
        //     }
        //     if (carry){
        //         // carry successful
        //         to_add--; carry--;
        //     }
            
        // }
        // brute, check all upto n/2;
        for(int i=1; i<= n/2; i++){
            if (check(i) && check(n-i)) return {i, n-i};
        }
        return {-1,-1};
    }
};