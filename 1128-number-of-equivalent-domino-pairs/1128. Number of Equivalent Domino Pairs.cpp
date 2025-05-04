/////// O(n^2) Solution->
// class Solution {
// public:
//     int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//         int count = 0;
//         for (int i=0; i<dominoes.size(); i++){
//             sort(dominoes[i].begin(), dominoes[i].end());
//             vector<int>temp = dominoes[i];
//             // cout<<"The temp = ";
//             // for(auto &k:temp) cout<<k<<" ";
//             // cout<<endl; 
//             for (int j=i+1; j<dominoes.size(); j++){
//                 sort(dominoes[j].begin(),dominoes[j].end());
//                 if (temp == dominoes[j]){
//                     count++;
//                 }  
//             }
//         }
//         return count;
//     }
// };

// The below is the O(n*log(m)) n-> the numer of dominoes, log(m) ->insertion time for the vector in mp
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        map<vector<int>,int>mp;
        for (int i=0; i<dominoes.size(); i++){
            sort(dominoes[i].begin(),dominoes[i].end());
            mp[dominoes[i]]++;    
        }
        for (auto &i:mp){
            int temp_count = i.second;
            count+= (temp_count*(temp_count-1))/2;
        }
        return count;
    }
};