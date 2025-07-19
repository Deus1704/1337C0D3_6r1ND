#define pii pair<int,int>
class Solution {
public:
    bool dijkstra(int x,vector<vector<pii>>&adj,  vector<bool>& online, long long k, int n){
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0; pq.push({0, 0});
        while (!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            if (u==n-1) return true;
            for (auto [v,w]:adj[u]){
                if (w<x || (v != n-1 && !online[v])) continue;
                long long nd = d+w;
                if (nd > k || nd >= dist[v]) continue;
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pii>>adj(n);
        int low = 1, high = 0;
        for (auto &i:edges){
            adj[i[0]].push_back({i[1], i[2]});
            high = max(high, i[2]);
        }
        int maxy = -1;
        while (low<=high){
            int mid = low + (high - low) / 2; 
            if (dijkstra(mid, adj, online, k, n)){
                maxy = mid; low = mid+1;
            }else high = mid-1;
        }
        return maxy;
    }
};