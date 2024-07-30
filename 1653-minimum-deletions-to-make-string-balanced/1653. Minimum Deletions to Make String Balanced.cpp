class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int count = 0;
        for (auto cha:s){
            if (cha == 'b'){
                st.push(cha);
            }else if(cha == 'a' && !st.empty()){
                count++;
                st.pop();
            }
        }
        return count;
    }
};