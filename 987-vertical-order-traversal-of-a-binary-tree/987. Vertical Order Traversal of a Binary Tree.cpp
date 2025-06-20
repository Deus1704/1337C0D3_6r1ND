/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void rec(TreeNode* root, int col, int depth, map<int,vector<pair<int,int>>>&tp ){
        if (root == NULL) return ;
        tp[col].push_back({root->val, depth});
        // explore the left;
        rec(root->left, col-1, depth+1, tp);
        // explore the right;
        rec(root->right, col+1, depth+1, tp);
        return ;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if (root == NULL) return ans;
        map<int,vector<pair<int,int>>>tp;
        rec(root, 0, 0,tp);
        for (auto &i:tp){
            sort(i.second.begin(), i.second.end(), [](auto a,auto b){
                if (a.second==b.second) return a.first<b.first;
                else return a.second<b.second;
            });
            vector<int>temp; for (auto &j:i.second) temp.push_back(j.first);
            ans.push_back(temp);
        }
        return ans;
    }
};