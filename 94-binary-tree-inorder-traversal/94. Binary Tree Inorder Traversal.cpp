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
        void dfs_in(vector<int>&arr, TreeNode* root){
            if (root==NULL) return;
            dfs_in(arr, root->left);
            arr.push_back(root->val);
            dfs_in(arr, root->right);
        }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        dfs_in(ans, root);
        return ans;
    }
};