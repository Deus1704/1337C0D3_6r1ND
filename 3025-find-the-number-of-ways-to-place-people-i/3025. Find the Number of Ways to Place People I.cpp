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
            int start = 0;
            while (start<i){
                if (cords[start].first <= candidate.first && cords[start].second >= candidate.second){
                    bool can = true;
                    for (int j=0; j<n; j++){
                        if( j!= start && j!=i && 
                            cords[j].first>=cords[start].first  && cords[j].first<=candidate.first &&
                            cords[j].second>=candidate.second && cords[j].second<=cords[start].second){
                                can = false; break;
                            }
                    }
                    count+=can;
                }start++;
            }
        }
        return count;
    }
};