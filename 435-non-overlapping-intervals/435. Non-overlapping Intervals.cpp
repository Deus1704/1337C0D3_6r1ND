class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int count=0;
        int i=0, j=1;
        while (j<n){
            int current_start = intervals[i][0];
            int current_end = intervals[i][1];
            int next_start = intervals[j][0];
            int next_end = intervals[j][1];

            if (current_end <= next_start){
                i=j; j++;
            }else if (current_end <= next_end){
                // then greedily remove the jth interval because it has more width and might interfere more,
                j++; count++;
            }else if (current_end > next_end){
                i=j; count++; j++;
            }
        }
        return count;
    }
};