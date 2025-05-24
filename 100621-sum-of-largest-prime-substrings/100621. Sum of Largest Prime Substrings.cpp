class Solution {
public:
    bool is_prime(long long &n){
        if (n==1){
            return false;
        }
        for (long long i=2; i*i<=n; i++){
            if (n%i==0) return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        long long n= s.size(); set<long long>ss;
        
        for (long long i=0; i<n; i++){
            for (long long j=i+1; j<=n; j++){
                long long temp = stoll(s.substr(i,j-i));
                if (is_prime(temp)){
                    // cout<<"Now pushing="<<temp<<endl;
                    ss.insert(temp);
                }
            }
        }vector<long long>sss(ss.begin(),ss.end());
        sort(sss.rbegin(),sss.rend());
        long long count=0;for (long long i=0; i<sss.size(); i++) {
            if (i<3) count+=sss[i];
        }
        return count;
    }
};