class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        // map<int,int>mp; int mfq= 0, mfqe = 0; set<int>te(nums.begin(), nums.end());
        // for (auto &i:nums) { mp[i]++; if (mp[i]>mfq){mfq = mp[i]; mfqe=i;}}
        // if (k==1 || k==te.size()) return true;
        // // Now the max will be the one deciding the number of groups since Rule 2
        // // vector<int>temp(mfq, k-1);// All mfq assigned to each group
        // // mp.erase(mfqe); if(nums.size()-mfq < (k-1)*mfq ) return false;
        // // return (nums.size()-mfq)%(mfq*(k-1))==0;
        // vector<int>temp; for (auto &i:mp) temp.push_back(i.second); int n = temp.size();
        // vector<int>prefix(n+1,0), suffix(n+1, 0);
        // for (int i=1; i<n+1; i++){
        //     prefix[i] = prefix[i-1]+temp[i-1];
        //     suffix[n-i] = suffix[n+1-i]+temp[n-i];
        // }
        // for (auto &i:prefix) cout<<i<<","; cout<<endl;
        // for (auto &i:suffix) cout<<i<<","; cout<<endl;
        // for(int i=1; i<n; i++){
        //     if (prefix[i]==suffix[i] && prefix[i]==k) return true;
        // }
        // return false;
        // Fucker
        map<int,int>mp; for(auto &i:nums) mp[i]++;
        int n = nums.size(); int each_group_freq = n/k; if (n%k!=0) return false;
        for (auto &i:mp) if (i.second > each_group_freq) return false;
        return true;
    }
};