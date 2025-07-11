#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<pair<ll,ll>>m;
        for (auto &i:meetings) {m.push_back({i[0], i[1]});}
        sort(m.begin(), m.end());
        vector<ll>freq_each_room(n);
        ll maxy=0;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > used;
        priority_queue<ll, vector<ll>, greater<ll> > available;
        for (ll i=0; i<n; i++) available.push(i);
        for (auto &i:m){
            ll start_time = i.first, end_time = i.second;
            // if the start_time is greater than the least ending time in the used;
            while (!used.empty() && start_time>=used.top().first){
                const auto [dont_care, room] = used.top(); used.pop();
                // since this is already over, it needs to be present in the available one;
                available.push(room);
            }
            // if the available is empty
            if (available.empty()){
                // need to wait till the earliest room that is vacated
                const auto [ed, room] = used.top(); used.pop();
                end_time = (ed + (end_time-start_time) );
                available.push(room);
            }
            // if its not empty
            // we have a room to throw our meeting in;
            auto room_available = available.top(); available.pop();
            used.push({end_time, room_available});
            freq_each_room[room_available]++; maxy=max(maxy, freq_each_room[room_available]);
        }
        // cout<<"maxy="<<maxy<<", so the freq of 0="<<freq_each_room[0]<<", while that of 1="<<freq_each_room[1]<<endl;
        for (ll i=0; i<n; i++) if (freq_each_room[i] == maxy) return i;

        return 0;
    }
};