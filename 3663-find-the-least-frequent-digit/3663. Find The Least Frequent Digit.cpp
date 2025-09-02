class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int,int>mp;
        while (n){
            mp[n%10]++; n/=10;
        }
        int maxy=-1,fq=1e9;
        for(auto &i:mp){
            if (i.second < fq){
                fq = i.second; maxy = i.first;
            }
        }
        return maxy;
    }
};