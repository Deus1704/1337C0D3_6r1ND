#define pii pair<int,int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pii>>adj(n);
        for (auto it:flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int>distances(n); for (int &j:distances) j=1e9;
        queue<pair<int,pii>>q; q.push({0,{src, 0}}); // stores the steps ,node and price. Since we are allowed to iterate at max the k steps.
        distances[src]=0;
        while (!q.empty()){
            int steps = q.front().first, node=q.front().second.first, cost = q.front().second.second; 
            q.pop();
            if (steps>k) break;
            for (auto neigh:adj[node]){
                const auto [neighbor, price] = neigh;
                if (distances[neighbor] > price+cost ){
                    distances[neighbor]=price+cost;
                    q.push({steps+1, {neighbor, distances[neighbor]}});
                }
            }
        }
        return distances[dst]==1e9?-1:distances[dst];
    }
};