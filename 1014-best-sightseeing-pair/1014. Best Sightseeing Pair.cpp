                        // Brute; Using O(n^2)
// class Solution {
// public:
//     int maxScoreSightseeingPair(vector<int>& values) {
//         int max_score = INT_MIN;
//         for (int i=0; i<values.size(); i++){
//             for (int j=i+1; j<values.size(); j++){
//                 max_score = max(max_score, (values[j]+values[i]+i-j));
//             }
//         }
//         return max_score;
//     }
// };

                        // Better;
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_score = INT_MIN;
        vector<int>left;
        vector<int>right;
        int n = values.size();
        int cur_max = INT_MIN;
        for (int i=0; i<n; i++){
            cur_max = max(cur_max, values[i]+i);
            left.push_back(cur_max);
        }
        left.insert(left.begin(),0); // This so that the left of the 0th index is nothing hence 0;
        cur_max = INT_MIN;
        for (int i=n-1; i>=0; i--){
            cur_max = max(cur_max, values[i]-i);
            right.insert(right.begin(),cur_max);
        }
        right.push_back(0); // similarly nothing on the right of the n-1th index.
        for (int i=1; i<left.size()-1; i++){
            max_score = max(max_score, left[i]+right[i]);
        }
        return max_score;
        cout<<"First left array: ";
        for (auto &i:left) cout<<i<<",";
        cout<<endl;
        cout<<"Then right array: ";
        for (auto &i:right) cout<<i<<",";
        cout<<endl;
        return 1;
    }
};