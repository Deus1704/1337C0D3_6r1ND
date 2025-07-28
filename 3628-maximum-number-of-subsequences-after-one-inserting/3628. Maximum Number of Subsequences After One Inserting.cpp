class Solution {
public:
    long long numOfSubsequences(string s) {
        long long n = s.size(), maxL=0, maxT = 0;
        vector<long long>prefL(n+1), sufT(n+1);
        for (long long i=0; i<n; i++){
            prefL[i+1] = prefL[i]+ (s[i] == 'L');
            maxL = max(maxL, prefL[i+1]);
        }
        for (long long i=n-1; i>=0; i--){
            sufT[i] = sufT[i+1] + (s[i] == 'T');
            maxT = max(maxT, sufT[i]);
        }
        // for (auto &i:prefL) cout<<i<<","; cout<<endl;
        // for (auto &i:sufT) cout<<i<<","; cout<<endl;
        long long ans = 0, t1=0, t2=0, t3=0;
        // first pass, where we just add 'L' in the beginning
        for (long long i=0; i<n-1; i++){
            if (s[i] == 'C'){
                t1+= ( prefL[i] + 1) * (sufT[i]);
            }
        }
        ans = max(ans, t1);
        // Second pass, where we just add 'T' in the end
        for (long long i=1; i<n; i++){
            if (s[i] == 'C'){
                // cout<<"Got t2="<<t2<<endl;
                t2+= (prefL[i]) * (sufT[i]+ 1);
            }
        }
        ans = max(ans, t2);
        // Third pass, where we just add 'C' in the position where the maximum of prefix and suffix lies
        for (long long i=1; i<n-1; i++){
            if (s[i]=='C') t3+=prefL[i]*sufT[i];
        }
        long long max_prod = 0;
        for (int i=0; i<n; i++) max_prod = max(max_prod, sufT[i]*prefL[i]);
        // the case where we include a C for the first time.
        // ans = max(ans, t3);
        ans = max(ans, t3+max_prod);
        return ans;
    }
};