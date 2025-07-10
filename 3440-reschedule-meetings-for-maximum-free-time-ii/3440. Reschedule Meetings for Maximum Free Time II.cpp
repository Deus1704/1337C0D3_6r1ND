class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int>free_time; int last=0, n=startTime.size(), maxy=0; 
        // for width, and its pos
        // vector<pair<int,int>>mp; 
        // since the above way of having a vector of width and its start pos would go O(n^2), we need to pre-compute, the max
        for (int i=0; i<n; i++){
            free_time.push_back(startTime[i]-last);
            // mp.push_back({startTime[i]-last, last});
            last = endTime[i];
        }
        free_time.push_back(eventTime-last);
        vector<int>prefix_max(free_time.size()+1), suffix_max(free_time.size()+1);
        for (int i=1; i<=free_time.size(); i++){
            prefix_max[i] = max(prefix_max[i-1], free_time[i-1]);
        }
        for(int i=free_time.size()-1; i>=0; i--){
            suffix_max[i] = max(suffix_max[i+1], free_time[i]);
        }
        // mp.push_back({eventTime-last, last});
        // cout<<"now printing free_time="; for (auto &i:free_time) cout<<i<<","; cout<<endl;
        // cout<<"now printing prefix="; for (auto &i:prefix_max) cout<<i<<","; cout<<endl;
        // cout<<"now printing suffix="; for (auto &i:suffix_max) cout<<i<<","; cout<<endl;
        // for (int i=0; i<n; i++){
        //     int left_free=free_time[i].first, left_free_start=free_time[i].second, right_free = free_time[i+1].first, right_free_start = free_time[i+1].second;
        //     int size_of_ith_event = endTime[i]-startTime[i];
        //     for (auto &time:mp){
        //         // cout<<"now trying time="<<time.second<<", the left_free_start="<<left_free_start<<", while right_free_start="<<right_free_start<<endl;
        //         if ( time.first>=size_of_ith_event && time.second!=left_free_start && time.second!=right_free_start ){
        //             // cout<<"entered here, total="<<left_free+right_free+size_of_ith_event<<endl;
        //             maxy = max(maxy, left_free+right_free+size_of_ith_event);
        //         }
        //     }
        //     maxy = max(maxy, left_free+right_free);
        // }

        // New code;
        for (int i=1; i<=n; i++){
            int size_of_ith_event = endTime[i-1]-startTime[i-1];
            int left_max_free = prefix_max[i-1];
            int right_max_free = suffix_max[i+1];
            // cout<<"for the size_of_ith_event="<<size_of_ith_event<<", the left_max_free="<<left_max_free<<", while right_max_free="<<right_max_free<<endl;
            if (size_of_ith_event > max(left_max_free, right_max_free)){
                maxy = max(maxy, free_time[i]+free_time[i-1]);
            }else{
                maxy=max(maxy, free_time[i]+free_time[i-1]+size_of_ith_event);
            }
        }
        return maxy;
    }
};