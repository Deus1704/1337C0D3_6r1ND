int n = 0;
class Solution {
public:
    vector<int>ngeleft(vector<int>& nums){
        vector<int>res(n, -1);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            if (!st.empty())res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    vector<int>ngeright(vector<int>& nums){
        vector<int>res(n, -1);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[i] >= nums[st.top()]){
                st.pop();
            }
            if (!st.empty())res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    long long bowlSubarrays(vector<int>& nums) {
        n = nums.size();
        vector<int>ngeL = ngeleft(nums), ngeR = ngeright(nums);
        // for(auto &i:ngeL) cout<<i<<","; cout<<endl;
        // for(auto &i:ngeR) cout<<i<<","; cout<<endl;
        long long count=0;
        for(int i=0; i<n; i++){
            if ( ngeL[i]>=0 && ngeL[i] < i-1) count++;
            if (ngeR[i]>=0 && ngeR[i]>i+1) count++;
        }
        return count;
    }
};