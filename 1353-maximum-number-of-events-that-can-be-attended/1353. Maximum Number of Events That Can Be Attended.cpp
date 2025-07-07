#define pii pair<int,int>
class Solution {
public:
    int maxEvents(vector<vector<int>>& e) {
        int n = e.size();
        sort(e.begin(), e.end());
        priority_queue<int,vector<int>, greater<int>>pq;
        int timer = e[0][0], i=0, count=0;
        while ( i<n || !pq.empty() ){
            while (i<n && e[i][0]==timer) {pq.push(e[i][1]);i++;}
            if (!pq.empty()){
                pq.pop();
                count++;
            }
            timer++;
            while (!pq.empty() && pq.top()<timer){
                pq.pop();
            }
        }
        return count;
    }
};