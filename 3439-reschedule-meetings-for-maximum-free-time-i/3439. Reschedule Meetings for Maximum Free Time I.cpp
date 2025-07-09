class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), last=0;
        vector<int>free_time;
        for (int i=0; i<n; i++){
            free_time.push_back(startTime[i]-last);
            last = endTime[i];
        }
        if (last != eventTime) free_time.push_back(eventTime-last);
        // for (auto &i:free_time) cout<<i<<",";
        int l=0,r=0, max_free_time = 0, summ=0;
        while (r<free_time.size()){
            while (r<free_time.size() && r-l+1 <= k+1){
                summ+=free_time[r];r++;
                max_free_time = max(max_free_time, summ);
            }
            if (r-l+1 > k+1){
                summ-=free_time[l]; l++;
            }
        }
        return max_free_time;
    }
};