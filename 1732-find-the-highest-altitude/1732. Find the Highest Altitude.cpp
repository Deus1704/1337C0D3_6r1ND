class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int alt = 0;
        for (int i=0; i<gain.size(); i++){
            highest = max(highest, alt+gain[i]);
            alt+=gain[i];
        }
        return highest;
    }
};