#define pii pair<int,int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>>adj(n+1);
        for (auto i:times){
            adj[i[0]].push_back({i[2], i[1]});
        }
        vector<int>distances(n+1); for (auto &i:distances) i=1e9;
        distances[k]=0;
        priority_queue<pii,vector<pii>, greater<pii>>pq;
        pq.push({0, k});
        while (!pq.empty()){
            const auto [time, node] = pq.top(); pq.pop();
            for (auto neighbor:adj[node]){
                const auto [t, target] = neighbor;
                if (distances[target] > time+t){
                    distances[target]=time+t;
                    pq.push({distances[target], target});
                }
            }
        }
        int mini=-1e9;
        for (int i=1; i<n+1; i++){
            if (i!=k) mini = max(mini, distances[i]);
        }
        return mini==1e9?-1:mini;
    }
};