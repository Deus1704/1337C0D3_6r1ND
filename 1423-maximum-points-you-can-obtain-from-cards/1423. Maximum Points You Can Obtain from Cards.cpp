class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int score=0;
        // need to use the sliding window method here, and check all the availalble options;
        for (int i=0; i<k; i++) score+=cardPoints[i];
        // now simulate removing each from this window and adding from the right;
        int temp = score, indi = k-1;
        for (int i=n-1; i>n-k-1; i--){
            temp-=cardPoints[indi];indi--;
            temp+=cardPoints[i];
            score = max(temp, score);
        }
        return score;
    }
};

// ---------------------- Greedy did not work here -----------------
// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int l=0,n=cardPoints.size();int r=n-1;
//         int score=0;
//         while (k--){
//             if (cardPoints[l]==cardPoints[r]){
//                 if ( (l+1<n && r-1>=0) &&  cardPoints[l+1]>cardPoints[r-1] ){
//                     score+=cardPoints[l];l++;
//                 }else{
//                     score+=cardPoints[r];r--;
//                 }
//             }else if (cardPoints[l]>cardPoints[r] ){
//                 score+=cardPoints[l];
//                 l++;
//             }
//             else{
//                 score+=cardPoints[r];
//                 r--;
//             }
//             cout<<"The score="<<score<<", l="<<l<<",r="<<r<<endl
//         }
//         return score;
//     }
// };