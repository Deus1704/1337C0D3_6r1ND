// class Solution {
// public:
//     int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
//         int n = fruits.size();
//         vector<int>frutie(max(fruits[n-1][0]+1, startPos));
//         for (int i=0; i<n; i++) frutie[fruits[i][0]] = fruits[i][1];
//         vector<int>prefix(frutie.size()+1); for (int i=1; i<frutie.size()+1; i++) prefix[i] = prefix[i-1]+frutie[i-1];
//         int ans=0, left=0, right=0;
//         // for (auto &i:frutie) cout<<i<<","; cout<<endl;
//         // left k window
//         left = prefix[startPos]-prefix[startPos-k];
//         ans = max(ans, left);
//         // right k window
//         right = prefix[startPos+k+1]-prefix[startPos];
//         ans = max(ans, right);
//         cout<<"Got left="<<left<<", and right="<<right<<endl;
//         // Now try the way where x in left and k-2x in right
//         // int x=1;
//         // while (k-2*x >= 0){
//         //     int total_picked=0;
//         //     // cout<<"Trying x="<<x<<endl;
//         //     // x in left;
//         //     for (int i=startPos; i>=max(startPos-x,0); i--){
//         //         // cout<<"Trying out i="<<i<<endl;
//         //         total_picked+=frutie[i];
//         //     }
//         //     // cout<<"Got the picked="<<total_picked<<endl;
//         //     for (int i=startPos+1; i<=min(startPos+(k-2*x)+1,(int)frutie.size()-1); i++){
//         //         // cout<<"Trying out i="<<i<<endl;
//         //         total_picked+=frutie[i];
//         //     }
//         //     // cout<<"Got the picked="<<total_picked<<endl;
//         //     ans = max(ans, total_picked);
//         //     x++;
//         // }
//         // // Again try with x in the right and k-2*x in the left;
//         // // x=1; cout<<"Right x\n";
//         // while (k-2*x >= 0){
//         //     int total_picked=0;
//         //     // cout<<"Trying x="<<x<<endl;
//         //     // x in right;
//         //     for (int i=startPos; i<=min(startPos+x,(int)frutie.size()-1); i++){
//         //         // cout<<"Trying out i="<<i<<endl;
//         //         total_picked+=frutie[i];
//         //     }
//         //     // cout<<"Got the picked="<<total_picked<<endl;
//         //     for (int i=startPos-1; i>=max(startPos+(k-2*x)-1, 0); i--){
//         //         // cout<<"Trying out i="<<i<<endl;
//         //         total_picked+=frutie[i];
//         //     }
//         //     // cout<<"Got the picked="<<total_picked<<endl;
//         //     ans = max(ans, total_picked);
//         //     x++;
//         // }
//         return ans;
//     }
// };
class Solution {
public:
    int step(int R, int L, int startPos) {// goes left then right but also right then left
        return min(startPos-2*L+R, 2*R-startPos-L);// both should > k
    }
    
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int i0=lower_bound(fruits.begin(), fruits.end(), vector<int>(1,startPos-k))-fruits.begin();
        int iN=upper_bound(fruits.begin()+i0, fruits.end(), vector<int>(1,startPos+k+1))-fruits.begin();

        int ans=0, wsum=0;
        for (int l=i0, r=i0; r<iN; r++) {
            wsum+=fruits[r][1];
            const int R=fruits[r][0];
            while (l<=r && step(R, fruits[l][0], startPos) > k){
                wsum-=fruits[l][1];
                l++;
            }
            ans=max(ans, wsum);
        }
        return ans;
    }
};
