class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0, index=0, n = height.size();
        vector<int>prefixMax(n), suffixMax(n);prefixMax[0] = height[0]; suffixMax[n-1]=height[n-1];
        for (int i=1; i<n; i++){
            prefixMax[i] = max(prefixMax[i-1], height[i]);
            suffixMax[n-i-1] = max(suffixMax[n-i], height[n-i-1]);
        }
        // for (auto i:prefixMax) cout<<i<<","; cout<<endl;
        // for (auto i:suffixMax) cout<<i<<","; cout<<endl;
        for (int i=0; i<n; i++){
            int mini = min(prefixMax[i], suffixMax[i]);
            if (mini>height[i]){
                ans+=mini-height[i];
            }
        }
        return ans;
    }
};