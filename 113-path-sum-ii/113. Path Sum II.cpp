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
    void rec(TreeNode* root, int ts, int cursum, vector<int>&temp, vector<vector<int>>&ans ){
        if (!root->left && !root->right){
            if (cursum+root->val == ts){
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
            }
        }
        temp.push_back(root->val);
        if (root->left) {
            rec(root->left, ts, cursum+root->val, temp, ans);
        }if(root->right){
            rec(root->right, ts, cursum+root->val, temp, ans);
        }temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int ts) {
        vector<vector<int>>ans;
        if (!root) return ans;
        auto cur = root;
        vector<int>temp;
        rec(cur, ts, 0, temp, ans);
        return ans;
    }
};