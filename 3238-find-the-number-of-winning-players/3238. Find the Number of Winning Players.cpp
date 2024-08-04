class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int winners = 0;
        unordered_map<int,unordered_map<int,int>>cmp;
        for (auto it: pick){
            cmp[it[0]][it[1]]++;
        }
        for (auto& it: cmp){
            for (auto& m: it.second){
                if (m.second >= it.first+1){
                    winners++;
                    break;
                }
            }
        }
        return winners;
    }
};