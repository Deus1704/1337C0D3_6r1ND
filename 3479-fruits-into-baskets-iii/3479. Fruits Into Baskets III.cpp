class Solution {
public:
    void build(int node, int start, int end, vector<int>&a, vector<int>&segtree){
        if (start == end){
            segtree[node] = a[start];
            return;
        }
        int mid = start + (end-start)/2;
        // build left
        build(2*node+1, start, mid, a, segtree);
        // build right
        build(2*node+2, mid+1, end, a, segtree);

        segtree[node] = max(segtree[2*node+1], segtree[2*node+2]);
    }
    bool query_seg(int node, int start, int end, vector<int>&segtree, int fruit){
        // if the fruit value is greater than the top most, then its directly not possible
        if (segtree[node] < fruit) return false;
        if (start == end){
            segtree[node] = -1; return true;
        }
        int mid = start + (end-start)/2;
        bool left_found=false, right_found=false;
        if (segtree[2*node+1] >= fruit){
            // THen go left
            left_found = query_seg(2*node+1, start, mid, segtree, fruit);
        }else{
            // Go right
            right_found = query_seg(2*node+2, mid+1, end, segtree, fruit);
        }
        // also update since we are makign the changes in the segment tree;
        segtree[node]  = max(segtree[2*node+1], segtree[2*node+2]);

        return left_found || right_found;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        // This is O(n^2) , passed 719/740
        // set<int>visited;
        // stack<int>st; for (int i=n-1; i>=0; i--) st.push(baskets[i]);
        // vector<pair<int,int>>combined; for (int i=0; i<n; i++) combined.push_back({baskets[i], i});
        // sort(combined.begin(), combined.end, [](auto a, auto b){
        //     return a.first<b.first;
        // })
        // int count_of_included=0;
        // for (int i=0; i<n; i++){
        //     // vector<int>temp;
        //     // while (!st.empty() && st.top()<fruits[i]){
        //     //     temp.push_back(st.top()); st.pop();
        //     // }
        //     // if (!st.empty()){
        //     //     count_of_included++;
        //     //     st.pop();
        //     // }
        //     // // for (auto &j:temp) cout<<j<<","; cout<<endl;
        //     // // re enter all the popped elements;
        //     // for (int num=temp.size()-1; num>=0; num--) st.push(temp[num]);
        // }
        vector<int>segtree(4*n,-1);
        build(0, 0, n-1, baskets, segtree);
        int count_of_unplaced = 0;
        for (auto &i:fruits){
            if(!query_seg(0,0,n-1,segtree, i)){
                count_of_unplaced++;
            }
        }
        return count_of_unplaced;
    }
};