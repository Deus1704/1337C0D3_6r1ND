class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0, left=0, right=0, n=fruits.size();
        map<int,int>mp;
        while (right<n && left<n){
            while (right<n ){
                mp[fruits[right]]++; 
                if (mp.size()<=2) right++;
                else break;
            }
            // for (auto &i:mp) cout<<"Fruit type="<<i.first<<", and count="<<i.second<<endl;
            // cout<<"Got right="<<right<<endl;
            ans = max(ans, right-left);
            // cout<<"Got ans="<<ans<<endl;
            while (left<n && mp.size() > 2){
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
                if (mp.size()==2) break;
            }
            // for (auto &i:mp) cout<<"Fruit type="<<i.first<<", and count="<<i.second<<endl;
            // cout<<"Got left="<<left<<endl;
            right++;
        }
        return ans;
    }
};