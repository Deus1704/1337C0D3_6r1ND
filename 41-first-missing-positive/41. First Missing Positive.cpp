class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        // again need O(n) but auxillary needs to be O(1)
        // Cannot use the PHP since the values in the array may be negative so this means PHP wont be followed.
        // First pass, mark all negative values as 0;
        int n = a.size();
        for (auto &i:a) if (i<0) i=0;
        for (int i=0; i<n; i++){
            int val = abs(a[i])-1;
            if ( val>=0 && val<n ){
                if (a[val]>0) a[val]*=-1;
                else if (a[val]==0) a[val]=-1*(n+1);
            }
        }
        // for (auto &i:a) cout<<i<<","; cout<<endl;
        for (int i=1; i<=n; i++){
            if (a[i-1] >= 0 ) return i;
        }
        return n+1;
        // Say Better solution is the use of sorting and then move and check;
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // int prev = 0,ans = -1;
        // for (int i=0; i<n-1; i++){
        //     if (nums[i]<0) continue;
        //     else{
        //         if (nums[i] == prev) prev++;
        //         else{
        //             ans = prev;
        //         }
        //     } 
        // }
        // return ans;
    }
};