class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxi = 0; 
        for (auto i:candies){
            maxi = max(maxi, i);
        }
        for (int i =0; i<candies.size(); i++){
            if (candies[i] + extraCandies >= maxi) result.push_back(true);
            else{ result.push_back(false);}
        }
        return result;
    }
};