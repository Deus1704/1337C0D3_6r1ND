class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>sta;
        for (auto ch : logs){
            if (ch == "../"){
                if (!sta.empty()) sta.pop();
            }else if(ch == "./"){
                continue;
            }else{
                sta.push(ch);
            }
        }
        return sta.size();
    }
};