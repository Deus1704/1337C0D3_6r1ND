class DisjointSet{
    public:
        vector<int>size, parent;
        DisjointSet(int n){
            size.resize(n,1); parent.resize(n); for (int i=0; i<n; i++) parent[i]=i;
        }
        int FindUltimateParent(int node){
            if (parent[node] == node) return node;
            return parent[node] = FindUltimateParent(parent[node]);
        }
        void UnionBySize(int node_u, int node_v){
            int UPu = FindUltimateParent(node_u), UPv = FindUltimateParent(node_v);
            if (UPu == UPv) return;
            if (size[UPu]>=size[UPv]){
                parent[UPv] = UPu;
                size[UPu]+=size[UPv];
            }else{
                parent[UPu] = UPv;
                size[UPv]+=size[UPu];
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int>mp; int n = accounts.size();
        DisjointSet ds(n);
        for (int i=0; i<n; i++){
            for (int j=1; j<accounts[i].size(); j++){
                if (mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }else{
                    ds.UnionBySize(ds.parent[mp[accounts[i][j]]], i);
                }
            }
        }
        map<int, set<string>>st;
        for (auto &it:mp){
            // cout<<"So email="<<it.first<<" -> "<<it.second<<endl;
            int ultimate_parent = ds.FindUltimateParent(it.second);
            st[ultimate_parent].insert(it.first);
        }
        // for (auto &i:ds.parent) cout<<i<<","; cout<<endl;
        vector<vector<string>>ans;
        for (auto &i:st){
            vector<string>temp; temp.push_back(accounts[i.first][0]);
            for (auto &j:i.second) temp.push_back(j);
            ans.push_back(temp);
        }
        return ans;
    }
};