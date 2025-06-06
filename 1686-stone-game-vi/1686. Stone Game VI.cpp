class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int,pair<int,int>>>temp; int n = bobValues.size();
        for (int i=0; i<n; i++){
            temp.push_back({{aliceValues[i]+bobValues[i]},{aliceValues[i],bobValues[i]}});
        }
        sort(temp.begin(),temp.end());reverse(temp.begin(),temp.end());
        int alice_score = 0, bob_score = 0, index=0;
        while (index<n){
            if (index%2==0){
                // alice's turn
                alice_score+=temp[index].second.first;
            }else{
                // bob's turn
                bob_score+=temp[index].second.second;
            }
            index++;
        }
        if (alice_score>bob_score) return 1;
        else if (alice_score==bob_score) return 0;
        else return -1;
    }
};