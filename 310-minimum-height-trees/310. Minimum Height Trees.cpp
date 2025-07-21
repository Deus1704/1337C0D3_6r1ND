class Solution {
public:
    // int bfs(int start, vector<vector<int>>&adj, int n){
    //     vector<int>visited(n,0); 
    //     queue<int>q; q.push(start); visited[start]=1;
    //     int depth = 0;
    //     while (!q.empty()){
    //         depth++;
    //         int siz = q.size();
    //         while (siz--){
    //             int node = q.front(); q.pop();
    //             for (auto & neighbor:adj[node]){
    //                 if (!visited[neighbor]){
    //                     visited[neighbor]=1;
    //                     q.push(neighbor);
    //                 }
    //             }
    //         }
    //     }
    //     return depth-1;
    // }
    // O(N^2) solution, Brute
    // vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    //     vector<pair<int,int>>heights;
    //     vector<vector<int>>adj(n);
    //     for (auto &i:edges){
    //         adj[i[0]].push_back(i[1]);
    //         adj[i[1]].push_back(i[0]);
    //     }
    //     for (int i=0; i<n; i++){
    //         // for ith node as the root, calculate the depth using level order traversal.
    //         heights.push_back({bfs(i,adj, n), i});
    //     }
    //     // for (auto &i:heights) cout<<"index = "<<i.second<<", and its height="<<i.first<<endl;
    //     sort(heights.begin(), heights.end());
    //     int miniht = heights[0].first;
    //     vector<int>ans;
    //     for (auto [height, node]: heights){
    //         if (height > miniht) break;
    //         else ans.push_back(node);
    //     }
    //     return ans;
    // }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>>heights;
        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for (auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            indeg[i[1]]++; indeg[i[0]]++;
        }
        vector<int>leaves; for (int i=0; i<n; i++) if (indeg[i]<=1) { leaves.push_back(i); indeg[i]=0;}
        int count = leaves.size();
        while(count<n){
            vector<int>newLeafs;
            for (auto leaf:leaves){
                for (auto &neighbor:adj[leaf]){
                    indeg[neighbor]--;
                    if (indeg[neighbor]==1) newLeafs.push_back(neighbor);
                }
                indeg[leaf] = 0;
            }
            count+=newLeafs.size();
            leaves = newLeafs;
        }
        // for (auto &i:leaves) cout<<i<<", "; cout<<endl;
        // for (auto &i:indeg) cout<<i<<", "; cout<<endl;
        return leaves;
    }
};