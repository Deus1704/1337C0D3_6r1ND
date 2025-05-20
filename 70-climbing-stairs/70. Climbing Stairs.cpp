class Solution {
public:
    int rec(int i, int n, vector<int>&arr){
        //base case
        if (i==n) return 1; // 1 cause if I am on the n'th stair then it makes a possible case
        else if (i>n) return 0;
        // Recurse and check all ways;
        if (arr[i]!=0) return arr[i];
        int ans= 0;
        for (int j=1; j<3; j++){
            if (i+j<=n) ans+=rec(i+j,n, arr);
        }
        return arr[i]=ans;
    }
    int climbStairs(int n) {
        vector<int>arr(45,0);
        return rec(0,n, arr);    
    }
};