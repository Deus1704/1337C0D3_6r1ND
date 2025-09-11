class Solution {
public:
    int rec(int index, vector<string>& arr, set<char>&st ) {// -> The rec should return the maximum possible length of the valid Subsequence, from i to N
        // base case? -> 
        if (index == arr.size()) return 0; // if at the end, there is no string to compare to join so the len = 0;
        int maxi_len = 0;
        // try to place the arr[index] into our sequence, if valid, then its length will be added to our answer
        int include_length = 0; bool can = true; set<char>temp;
        for(auto &i:arr[index]) {
            if (temp.count(i)){ can = false; break; }
            if (st.count(i)){ can = false; break; }
            temp.insert(i);
        }
        if (can){
            for(auto &i:arr[index]) st.insert(i);
            include_length = arr[index].size() + rec(index+1, arr, st);
            for(auto &i:arr[index]) st.erase(i); // for backtracking
        }
        // Try to not include this
        int not_include_length = rec(index+1, arr, st);

        return max(include_length, not_include_length);
    }
    int maxLength(vector<string>& arr) {
        // sort based on their length
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.size()<b.size();
        });
        // Now we just want the Longest Increasing Subsequence where the elements do not share any common characters;
        // vector<int>dp(arr.size()+1, -1);
        set<char>st; 
        return rec(0, arr, st);
    }
};