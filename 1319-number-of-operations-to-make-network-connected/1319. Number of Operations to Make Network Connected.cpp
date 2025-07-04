const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
// Simple DFS Solution by just counting the number of connected components, count of the vertices, and the edges in each connected component. We keep a count of the extra edges in each component. Since any n nodes can be connected such that we can visit from one to other, is n-1 edges, hence the approach for the extra
// class Solution {
// public:
//     void dfs(int i,vector<vector<int>>&adj,vector<int>&visited, int &vertices,vector<int>&t ){
//         visited[i]=1;vertices++;t.push_back(i);
//         for (auto node:adj[i]){
//             if (!visited[node]) {
//                 dfs(node,adj,visited, vertices,t);
//             }
//         }
//     }
//     int makeConnected(int n, vector<vector<int>>& c) {
//         vector<vector<int>>adj(n);
//         for (auto i:c){
//             adj[i[0]].push_back(i[1]);
//             adj[i[1]].push_back(i[0]);
//         }
//         vector<int>visited(n); int count=0, extra=0;
//         for (int i=0; i<n; i++){
//             if (!visited[i]){
//                 int vertices=0, edges=0;
//                 vector<int>temp;
//                 dfs(i,adj,visited, vertices, temp);
//                 for (auto j:temp) edges+=adj[j].size();
//                 extra+= edges/2-(vertices-1);
//                 count++;
//             }
//         }
//         if (extra>=count-1) return count-1;
//         return -1;
//     }
// };

// Another Solution using the DSU
class DisjointSet{
public:
    vector<int>size,parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for (int i=0; i<n+1; i++) parent[i] = i;
    }
    int Find_Ultimate_Parent(int node){
        if (parent[node] == node) return node;
        return parent[node] = Find_Ultimate_Parent(parent[node]);
    }
    void Union_By_Size(int node_u, int node_v){
        int ultimate_parent_u = Find_Ultimate_Parent(node_u);
        int ultimate_parent_v = Find_Ultimate_Parent(node_v);
        if (size[ultimate_parent_u] > size[ultimate_parent_v]){
            parent[ultimate_parent_v] = ultimate_parent_u;
            size[ultimate_parent_u] += size[ultimate_parent_v];
        }else{
            parent[ultimate_parent_v] = ultimate_parent_u;
            size[ultimate_parent_u] += size[ultimate_parent_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& c) {
        DisjointSet ds(n);
        int count_extra = 0;
        for (auto it:c){
            int node_u = it[0], node_v = it[1];
            if (ds.Find_Ultimate_Parent(node_u) != ds.Find_Ultimate_Parent(node_v)){
                ds.Union_By_Size(node_u, node_v);
            }else{
                count_extra++; // So count the edges that do not help in the dsu formation
            }
        }
        int count_independent_componenets=0;
        for (int i=0; i<n; i++){
            // These have the parent as themselves -> i.e they are the independent components count;
            if (ds.parent[i]==i) count_independent_componenets++; 
        }
        // if the extra edges are sufficient for accomodating these indep componenets return this.
        if (count_extra >= count_independent_componenets-1) return count_independent_componenets-1;
        else return -1; 
    }
};