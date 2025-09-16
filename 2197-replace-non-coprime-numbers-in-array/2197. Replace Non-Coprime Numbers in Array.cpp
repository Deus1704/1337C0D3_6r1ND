class Solution {
public:
    // void sieve(vector<int>&primes, int n){
    //     vector<bool>table(n+1, true);
    //     for(int i=2; i*i<=n; i++){
    //         for(int j=2*i; j<=n; j+=i){
    //             if (table[j]) table[j]=false;
    //         }
    //     }
    //     for(int i=2; i<=n; i++){
    //         if (table[i]) primes.push_back(i);
    //     }
    // }
    // int gcd(int a, int b, vector<int>&primes){
    //     int mini = min(a, b), maxy = -1;
    //     for(int i=0; primes[i]<mini ; i++){
    //         if (a%primes[i] == 0 && b%primes[i] == 0) maxy=max(maxy, primes[i]);
    //     }
    //     if (maxy == -1) return 1; 
    //     return maxy;
    // }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size(), maxy = *max_element(nums.begin(), nums.end());
        // vector<int>primes;
        // sieve(primes, maxy);
        vector<int>result; result.push_back(nums[0]);
        for(int i=1; i<n; i++){
            int prev = result.back(); 
            // int gc = gcd(nums[i], prev, primes);
            int gc = gcd(nums[i], prev);
            // cout<<"For prev="<<prev<<", and nums[i]="<<nums[i]<<", the gcd="<<gc<<endl;
            if (gc>1){
                result.pop_back();
                prev = (prev/gc)*(nums[i]);
                while(result.size() && gcd(result.back(), prev) > 1){
                    prev = (prev/gcd(result.back(), prev))*result.back(); result.pop_back();
                }
                result.push_back(prev);
            }else result.push_back(nums[i]);
        }
        // for(auto &i:primes) cout<<i<<","; 
        return result;
    }
};