class Solution {
public:
    void genPrimes(int n, set<int>&s){
        vector<int>temp(n+1,1);
        for (int i=2; i<=n; i++){
            for (int j=2*i; j<=n; j+=i){
                temp[j]=0;
            }
        }
        // for (auto i:temp) cout<<i<<","; cout<<endl;
        for (int i=2; i<=n; i++){
            if (temp[i]) s.insert(i);
        }
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;for(auto i:nums) mp[i]++;
        set<int>primes;genPrimes(n,primes);
        // for (auto i:primes) cout<<i<<","; cout<<endl;
        for (auto &i:mp){
            if (  primes.count(i.second) ) return true;
        }
        return false;
    }
};