class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if (n%2){
            // odd so {,,,, 0 ,,,,} style
            ans.push_back(0);
            for(int j=1; j<=(n-1)/2; j++){
                ans.insert(ans.begin(), j);
                ans.insert(ans.end(), (-1)*j);
            }
        }else{
            for(int j=1; j<=n/2; j++){
                ans.insert(ans.begin(), j);
                ans.insert(ans.end(), (-1)*j);
            }
        }
        return ans;
    }
};