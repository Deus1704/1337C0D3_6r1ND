class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char>st1;
        stack<char>st2;
        string big,small;
        int summ = 0;
        int bigNo=0,smallNo=0;
        if (x>y){
            big = "ab";
            small ="ba";
            bigNo = x;smallNo=y;
        }else{
            big = "ba";
            small ="ab";
            bigNo = y;smallNo=x;
        }
        for(auto ch : s){
            if (ch == big[1] && !st1.empty() && st1.top()==big[0]){
                st1.pop();
                summ+=bigNo;
            }else{
                st1.push(ch);
            }
        }
        while(!st1.empty()){
            char ch = st1.top();
            st1.pop();
            if (ch ==small[0] && !st2.empty() && st2.top()==small[1]){
                st2.pop();
                summ+=smallNo;
            }else{
                st2.push(ch);
            }
        }
        return summ;
    }
};