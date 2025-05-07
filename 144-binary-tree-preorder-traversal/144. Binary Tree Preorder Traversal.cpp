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
    void dfs_pre(vector<int>&arr, TreeNode* root){
        if (root == NULL){ return; }
        arr.push_back(root->val);
        dfs_pre(arr, root->left);
        dfs_pre(arr, root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        dfs_pre(ans, root);
        return ans;
    }
};