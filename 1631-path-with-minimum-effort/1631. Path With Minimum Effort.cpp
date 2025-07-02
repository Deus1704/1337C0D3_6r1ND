class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size(), m=h[0].size();
        vector<vector<int>>distances(n,vector<int>(m));
        for (auto &i:distances) for (auto &j:i) j=INT_MAX;
        distances[0][0]=0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>  >pq;
        pq.push({0,{0,0}});
        // Need to travel in : up, right , down, left
        vector<pair<int,int>>d = {{-1,0},{0,1},{1,0},{0,-1}}; 
        while (!pq.empty()){
            const auto [x,y] = pq.top().second;
            int maxy = pq.top().first; pq.pop();
            for (auto dif:d){
                int newx = x+dif.first, newy= y+dif.second;
                if ( (newx>=0 && newx<n) && (newy>=0 && newy<m) && max(maxy, abs(h[newx][newy] - h[x][y]))<distances[newx][newy]){
                    distances[newx][newy] = min(distances[newx][newy], max(maxy, abs(h[newx][newy] - h[x][y])) );
                    pq.push({distances[newx][newy], {newx,newy}});
                }
            }
        }
        return distances[n-1][m-1];
    }
};