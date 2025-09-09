// Brute Way -> O(n^2) TLE even with 
// class Solution {
// public:
//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         int timer = 1, peeps = 0;
//         priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>pq;
//         pq.push({1+forget, 1});
//         while (timer <= n){
//             vector<pair<int,int>>temp;
//             while (pq.top().first <= timer) pq.pop();
//             while (pq.top().second + delay <= timer && pq.top().first > timer){
//                 temp.push_back(pq.top());
//                 pq.pop();
//                 pq.push({timer+forget, timer});
//             }
//             for(auto &i:temp) pq.push(i);
//             if (timer == n) peeps = pq.size();
//             timer++;
//         }
//         return peeps;
//     }
// };
int MOD = 1e9+7;
class Solution {
public:
    int rec(int day, int delay, int forget, vector<int>&days){
        if (day == 1) return 1; // since only 1 person knew the secret at day 1
        if (days[day] != -1) return days[day]; 
        int total_people_who_can_share=0;
        for(int cur_day = day-forget+1; cur_day<=day-delay; cur_day++){
            if (cur_day>0) total_people_who_can_share = (total_people_who_can_share + rec(cur_day, delay, forget, days)) % MOD;
        }
        return days[day] = total_people_who_can_share;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total_peeps_on_dayn = 0;
        vector<int>days(n+1,-1); days[1]=1;
        for(int prev = n-forget+1; prev<=n; prev++){
            total_peeps_on_dayn = (total_peeps_on_dayn + rec(prev, delay, forget, days))%MOD;
        }
        return total_peeps_on_dayn;
    }
};