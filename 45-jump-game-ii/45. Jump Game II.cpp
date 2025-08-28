class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        priority_queue< int, vector<int>, greater<int>>pq; pq.push(n-1);
        while (!pq.empty() && pq.top()!=0){
            int cur_end = pq.top(); while(!pq.empty()) {pq.pop();} 
            steps++;
            int ptrj = cur_end;
            while ( ptrj>=0 ){
                if (cur_end-ptrj <= nums[ptrj]) pq.push(ptrj);
                ptrj--; 
            }
        }
        return steps;
    }
};