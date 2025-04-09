class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans={{}}; // This initiation is required or else there will be no entry point by default.
        for (auto &n:nums){
            cout<<"Now at n="<<n<<endl;
            vector<vector<int>>temp;
            for (auto &perm : ans){
                cout<<"Look Im here"<<endl;
                for (int j=0; j<=perm.size(); j++){
                    vector<int> perm_copy = perm;
                    cout<<"Inserting j="<<j<<endl;
                    perm_copy.insert(perm_copy.begin()+j, n);
                    temp.push_back(perm_copy);
                }
            }
            // for (auto &i:temp){
            //     for (auto &num:i) cout<<num<<",";
            //     cout<<endl;
            // }
            ans = temp;
        }
        return ans;
    }
};
