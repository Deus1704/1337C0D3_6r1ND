// For practice Aye
class DisjointSet{
    public:
        vector<int>parent,size;
        DisjointSet(int n ){
            parent.resize(n); size.resize(n,1); for (int i=0; i<n; i++) parent[i]=i;
        }
        int FindUP(int u){
            if (parent[u] == u) return u;
            return parent[u] = FindUP(parent[u]);
        }
        void UnionBySize(int u, int v){
            int UPu = FindUP(u), UPv = FindUP(v);
            if (UPu == UPv) return;
            if (size[UPu] > size[UPv]){
                parent[UPv] = parent[UPu];
                size[UPu]+=size[UPv];
            }else{
                parent[UPu] = parent[UPv];
                size[UPv]+=size[UPu];
            }
        }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 
        // Min heap banao bsdk
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> >edges;
        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                edges.push({ abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]) ,{i,j}});
            }
        }
        // sort(edges.begin(), edges.end());
        int mincost=0;
        DisjointSet d(n);
        while (!edges.empty()){
            int cost = edges.top().first; auto [u,v] = edges.top().second; edges.pop();
            if (d.FindUP(u) == d.FindUP(v)) continue;
            mincost+=cost; d.UnionBySize(u,v);
        }
        return mincost;
    }
};