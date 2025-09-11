class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int>sad;
        for(auto &friends:friendships){
            int u =friends[0]-1 , v = friends[1]-1;
            set<int>known_to_u(languages[u].begin(), languages[u].end());
            bool can = false;
            for(auto &lang:languages[v]){
                if (known_to_u.count(lang)){
                    can = true; break;
                }
            }
            if (!can) { sad.insert(u); sad.insert(v);}
        }
        // Now check the maximum language that these sad users speak
        vector<int>sad_logo_ki_bhasha(n+1, 0);
        int max_sad_jo_bolte = 0;
        for(auto &i:sad){
            for(auto & lang: languages[i]) {
                sad_logo_ki_bhasha[lang]++;
                max_sad_jo_bolte = max(max_sad_jo_bolte, sad_logo_ki_bhasha[lang]);
            }
        }
        // bas count of log jinko sikhana hai woh output dena hai, 
        return sad.size() - max_sad_jo_bolte;
    }
};