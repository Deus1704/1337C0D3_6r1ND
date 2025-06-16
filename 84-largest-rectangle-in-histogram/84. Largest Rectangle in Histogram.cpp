class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), ans=0;
        vector<int>left(n,0), right(n,0);
        stack<int>s;
        for (int i=0; i<n; i++){
            while (!s.empty() && heights[s.top()]>=heights[i]) s.pop();

            if (s.empty()) left[i]=0;
            else left[i] = s.top()+1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for (int i=n-1; i>=0; i--){
            while (!s.empty() && heights[s.top()]>=heights[i]) s.pop();

            if (s.empty()) right[i]=n-1;
            else right[i]=s.top()-1;
            s.push(i);
            ans = max(ans, (right[i]-left[i]+1)*heights[i]);
        }
        // cout<<"Now left;";for (auto &i:left) cout<<i<<","; cout<<endl;
        // cout<<"Now right;";for (auto &i:right) cout<<i<<","; cout<<endl;
        return ans;
    }
};