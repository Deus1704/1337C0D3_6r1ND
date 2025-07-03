#define pii pair<int,int>
class Solution {
public:
    int dijkstra(vector<vector<pii>>&adj, vector<int>&distances, int src, int dt){
        priority_queue<pii, vector<pii>, greater<pii>>pq; pq.push({0, src});
        while (!pq.empty()){
            const auto [cur_dist, node] = pq.top(); pq.pop();
            for (auto neighbor:adj[node]){
                const auto [nei , wt] = neighbor;
                if (distances[nei] > cur_dist+wt && cur_dist+wt<=dt ){
                    distances[nei] = cur_dist+wt;
                    pq.push({distances[nei] , nei });
                } 
            }
        }
        int count=0;
        for (int i=0; i<distances.size(); i++){
            if (i!=src && distances[i]<=dt) count++;
        }
        return count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<pii>>adj(n);
        for (auto i:edges){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        int mini = 1e9; set<int>pos; 
        // set basically for keeping the track of all nodes which have the min reaching. In sorted 
        for (int i=0; i<n; i++){
            vector<int>distances(n,1e9); distances[i]=0;
            // This is simple dijsktra but the func returns the count of distances less than the threshold. 
            int count = dijkstra(adj, distances, i, dt);
            // cout<<"for i="<<i<<", we got count="<<count<<endl;
            if (count <= mini){
                mini = count; pos.insert(i); 
            }
        }
        // cout<<pos.size()<<endl;
        // for (auto i:pos) cout<<i<<","; cout<<endl;
        // return 0;
        return *pos.rbegin(); // Returns the max in the set
    }
};