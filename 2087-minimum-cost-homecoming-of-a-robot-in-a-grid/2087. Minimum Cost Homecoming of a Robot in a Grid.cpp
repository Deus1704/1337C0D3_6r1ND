class Solution {
public:
    bool isValid(int x, int y, int n , int m){
        if (x>=0 && x<m && y>=0 && y<n) return true;
        return false;
    }
    // int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    //     int m=rowCosts.size(), n=colCosts.size();
    //     // each cell will begin with inf dist, and then store the min distance from the start pos;
    //     vector<vector<int>>distances(m , vector<int>(n,1e9));
    //     if (startPos == homePos) return 0;
    //     // up, right, down, left . Lets say the col movement is denoted with 1 and row movement with 0
    //     vector<pair<int,pair<int,int>>>dist = { {0, {-1,0}}, {1, {0,1}}, {0, {1,0}},  {1, {0,-1}}}; 
    //     queue<pair<int, pair<int,int>>>q; q.push({ 0 , {startPos[0], startPos[1]}});
    //     while (!q.empty()){
    //         int cost = q.front().first; auto [x,y] = q.front().second; q.pop();
    //         for (int i=0; i<4; i++){
    //             int newx = x+dist[i].second.first, newy = y+dist[i].second.second;
    //             if (isValid(newx, newy, n,m)){
    //                 // Cost determine only if the move is valid; Duh
    //                 int cost_in_direction_of_move = dist[i].first==1?colCosts[newy]:rowCosts[newx];
    //                 // cout<<"Moving to =("<<newx<<","<<newy<<"), and with cost upto="<<cost<<" cost_in_direction_of_move="<<cost_in_direction_of_move<<endl;
    //                 if (cost+cost_in_direction_of_move < distances[newx][newy]){
    //                     distances[newx][newy] = cost+cost_in_direction_of_move;
    //                     // cout<<"New distance="<<distances[newx][newy]<<endl;
    //                     q.push({distances[newx][newy], {newx, newy}});
    //                 }
    //             }
    //         }
    //     }
    //     return distances[homePos[0]][homePos[1]];
    // }
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int m = rowCosts.size(), n=colCosts.size();
        // int distx = abs(homePos[0]-startPos[0]), disty = abs(homePos[1]-startPos[1]);
        int cost = 0;
        // Just straight up add the row costs
        if (homePos[0] > startPos[0]){
            int temp = startPos[0]+1;
            while (temp<=homePos[0]){
                cost+=rowCosts[temp++];
            }
        }else{
            int temp = startPos[0]-1;
            while (temp>=homePos[0]){
                cost+=rowCosts[temp--];
            }
        }
        // Now Col costs;
        if (homePos[1] > startPos[1]){
            int temp = startPos[1]+1;
            while (temp<=homePos[1]){
                cost+=colCosts[temp++];
            }
        }else{
            int temp = startPos[1]-1;
            while (temp>=homePos[1]){
                cost+=colCosts[temp--];
            }
        }
        return cost;
    }
};