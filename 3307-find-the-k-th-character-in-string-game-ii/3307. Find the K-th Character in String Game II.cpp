// class Solution {
// public:
//     char kthCharacter(long long k, vector<int>& operations) {
//         string s="a";
//         int expo = ceil(log2(k));
//         for (int i=0; i<expo; i++){
//             if (operations[i]==0) s+=s;
//             else {
//                 string temp = s;
//                 for (auto &c:temp){
//                     if (c!='z')c = char(c+1);
//                     else c='a';
//                 }s+=temp;
//             }
//         }
//         return s[k-1];
//     }
// };
class Solution {
public:
    char kthCharacter(long long k, vector<int>& ops) {
        int n = ops.size();
        vector<long long>len(n+1);
        __int128 big = 1; // this is fine upto 128 bits 
        len[0]=1;
        for (int i=1; i<=n; i++){
            len[i] = min(len[i-1]*2, (long long)1e18);
        }
        int accumlater=0;
        for (int i=n; i>=1; i--){
            if (k>len[i-1]){
                k-=len[i-1];
                if (ops[i-1]) accumlater = (accumlater+1)%26;
            }
        }
        // cout<<"got the accumlater="<<accumlater<<endl;
        return char('a'+accumlater);
    }
};