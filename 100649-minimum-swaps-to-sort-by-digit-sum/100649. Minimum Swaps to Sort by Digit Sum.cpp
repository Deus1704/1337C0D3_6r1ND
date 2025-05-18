class Solution {
    int summ(string s){
        int su = 0;
        for (auto &i:s){
            su+=i-'0';
        }
        return su;
    }
public:
    int minSwaps(vector<int>& nums) {
        int count=0; int n=nums.size();
        vector<pair<int,int>>temp;
        for (auto &i:nums){
            temp.push_back({summ(to_string(i)),i});
        }
        vector<pair<int,int>>sorted_temp = temp;
        sort(sorted_temp.begin(),sorted_temp.end());
        // for (auto &i:temp){
        //     cout<<"i.first="<<i.first<<", i.second="<<i.second<<endl;
        // }
        unordered_map<int,int>mp; vector<int>perms(n);
        for (int i=0; i<n; i++){
            mp[sorted_temp[i].second] = i;
        }for (int i=0; i<n; i++){
            perms[i]=mp[temp[i].second];
        }vector<bool>visited(n,false);
        for (int i=0; i<n; i++){
            if (visited[i] || perms[i] == i) continue;
            int cycle_size = 0;
            int j=i;
            while (!visited[j]){
                visited[j]=true;
                j = perms[j];
                cycle_size++;
            }
            count+=cycle_size-1;
        }
        return count;
    }
};