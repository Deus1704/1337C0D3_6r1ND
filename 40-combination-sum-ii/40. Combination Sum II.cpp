class Solution {
public:

    void rec(vector<int>& candidates, int target, int index, vector<int>& visited, vector<int>&t, set<vector<int>>&temp){
        // base case;
        if (index >= candidates.size() or target<=0){
            if (target==0) {
                sort(t.begin(), t.end());
                temp.insert(t);
            }
            return;
        }
        // if the index is not already visited, then visit it and check all further possibilities.
        if (!visited[index]){
            // pick
            visited[index]++;
            t.push_back(candidates[index]);
            rec(candidates, target-candidates[index], index+1, visited, t, temp);
            // not pick and move on
            visited[index]--;t.pop_back();
            while (index<candidates.size()-1 && candidates[index]==candidates[index+1]) index++;
            rec(candidates, target, index+1, visited, t, temp);
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>temp;
        vector<int>t;
        vector<int>visited(candidates.size());
        sort(candidates.begin(), candidates.end());
        rec(candidates, target, 0, visited, t, temp);
        vector<vector<int>> ans(temp.begin(), temp.end());
        return ans;
    }
};
