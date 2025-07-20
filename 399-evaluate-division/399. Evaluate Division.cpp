class Solution {
public:
    double dijkstra(int start_node, int end_node, vector<vector<pair<double,int>>> &adj , int siz){
        priority_queue< pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>> >pq;
        vector<double>distances(siz, 1e9); distances[start_node]=0;
        pq.push({0, start_node});
        while (!pq.empty()){
            auto [distance, node] = pq.top(); pq.pop();
            for (auto [edgewt, neighbor]: adj[node]){
                if (distance+edgewt < distances[neighbor]){
                    distances[neighbor] = distance+edgewt ;
                    pq.push({distances[neighbor], neighbor});
                }
            }
        }
        return distances[end_node];
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        set<string>st; int index=0;
        map<string, int>mp;
        for (int i=0; i<n; i++){
            st.insert(equations[i][0]); st.insert(equations[i][1]);
            if (!mp[equations[i][0]]) mp[equations[i][0]] = ++index;
            if (!mp[equations[i][1]]) mp[equations[i][1]] = ++index;
        }
        // for (auto &i:mp){
        //     cout<<"the first="<<i.first<<", and second ="<<i.second<<endl;
        // }
        vector<vector<pair<double,int>>> adj(st.size()+1);
        for (int i=0; i<n; i++){
            // cout<<  mp[equations[i][0]]<< " --- " << log(values[i])<<" -->"<< mp[equations[i][1]]<<endl;
            // cout<<  mp[equations[i][1]]<< " --- " << log(values[i]) *(-1) <<" -->"<< mp[equations[i][0]]<<endl;
            adj[mp[equations[i][0]]].push_back({ log(values[i]) , mp[equations[i][1]] });
            adj[mp[equations[i][1]]].push_back({ log(values[i]) *(-1) , mp[equations[i][0]] });
        }
        vector<double>ans;
        for (auto &i:queries){
            if (st.count(i[0]) && st.count(i[1])){
                double min_dist = dijkstra( mp[i[0]], mp[i[1]], adj, st.size()+1 );
                ans.push_back( min_dist == 1e9? -1: exp(min_dist)  );
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};