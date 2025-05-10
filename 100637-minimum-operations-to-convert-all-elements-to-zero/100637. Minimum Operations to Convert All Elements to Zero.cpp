class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ops = 0;
        for (int x : nums) {
            while (!st.empty() && st.top() > x) st.pop();
            if (!st.empty() && st.top() == x) continue;
            if (x > 0) {
                ops++;
                st.push(x);
            }
        }
        return ops;
    }
};