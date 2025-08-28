class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        // The following is a BFS style solution. Completely Impromptu solution. TC->O(n^2) AC
        // priority_queue< int, vector<int>, greater<int>>pq; pq.push(n-1);
        // while (!pq.empty() && pq.top()!=0){
        //     int cur_end = pq.top(); while(!pq.empty()) {pq.pop();} 
        //     steps++;
        //     int ptrj = cur_end;
        //     while ( ptrj>=0 ){
        //         if (cur_end-ptrj <= nums[ptrj]) pq.push(ptrj);
        //         ptrj--; 
        //     }
        // }
        // return steps;
        
        // Optimised O(n) solution involves dealing with ranges;
        int l=0, r=0;
        while (r<n-1){
            int farthest = 0;
            for (int index = l; index<=r; index++){
                farthest = max(farthest, index+nums[index]);
            }
            // now new l would be just next to the current element if its non zero
            l = farthest>0?r+1:l;
            r = farthest;
            steps++;
        }
        return steps;
    }
};