class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int>comb, b1, b2;
        int n = basket1.size(), mini_ele = 1e9;
        for (int i=0; i<n; i++){ 
            comb[basket1[i]]++;b1[basket1[i]]++;
            comb[basket2[i]]++;b2[basket2[i]]++;
            mini_ele = min(mini_ele, min(basket1[i], basket2[i]));
        }
        for (auto &i:comb){ if (i.second %2 != 0) return -1; }
        long long ans=0;
        vector<int>to_change1, to_change2;
        // Find the non required things
        for (auto &i:b1){
            if (i.second > comb[i.first]/2){
                while (i.second > comb[i.first]/2) { to_change1.push_back(i.first); i.second--;}
            }
        }
        for (auto &i:b2){
            if (i.second > comb[i.first]/2){
                while (i.second > comb[i.first]/2) { to_change2.push_back(i.first); i.second--;}
            }
        }
        sort(to_change1.begin(), to_change1.end());
        sort(to_change2.rbegin(), to_change2.rend());
        for(int i=0; i<to_change1.size(); i++){
            ans+=min(2*mini_ele, min( to_change1[i], to_change2[i]) );
        }
        // for (auto &i:to_change1) cout<<i<<","; cout<<endl;
        // for (auto &i:to_change2) cout<<i<<","; cout<<endl;
        return ans;
    }
};