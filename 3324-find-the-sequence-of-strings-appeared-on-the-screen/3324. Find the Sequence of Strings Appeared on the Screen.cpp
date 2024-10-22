class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string letters = "abcdefghijklmnopqrstuvwxyz";
        bool reached_target = false;
        string s ="";
        int i =0;
        while (!reached_target && i<target.size()){
            size_t temp = letters.find(target[i]);
            cout<<temp<<endl;
            for (int j=0; j<=temp; j++){
                s+=letters[j];
                cout<<s<<endl;
                ans.push_back(s);
                s.pop_back();
            }
            s+=target[i];
            i++;
        }

        return ans;
    }
};