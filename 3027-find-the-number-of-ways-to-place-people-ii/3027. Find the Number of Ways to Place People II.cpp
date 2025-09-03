class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        vector<pair<int,int>>cords; int n = points.size();
        for(auto &i:points){
            cords.push_back({i[0], i[1]});
        }
        sort(cords.begin(), cords.end(), [](auto &a, auto &b){
            if (a.first == b.first) return a.second>b.second;
            return a.first<b.first;
        });
        int count = 0;
        for(int i=0; i<n; i++){
            auto candidate = cords[i];
            int start = i+1; int max_y = INT_MIN;
            // cout<<"The candidate=("<<candidate.first<<","<<candidate.second<<")"<<endl;
            while (start<n && start>i){
                // cout<<"trying pair=("<<cords[start].first<<","<<cords[start].second<<")"<<endl;
                if (cords[start].first >= candidate.first && cords[start].second <= candidate.second){
                    if (cords[start].second > max_y || candidate.second<max_y){
                        // cout<<"Succeeded"<<endl;
                        count++;
                        max_y = max(max_y, cords[start].second);
                    }
                }
                // Now the following would track all the y cords in bw the candidate and start
                // max_y = max(max_y, cords[start].second);
                start++;
            }
        }
        return count;
    }
};