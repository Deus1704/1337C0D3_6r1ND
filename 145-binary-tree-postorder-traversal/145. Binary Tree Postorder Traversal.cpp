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
        void dfs_post(vector<int>&arr, TreeNode* root){
            if (root==NULL) return;
            dfs_post(arr, root->left);
            dfs_post(arr, root->right);
            arr.push_back(root->val);
        }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        dfs_post(ans, root);
        return ans;
    }
};