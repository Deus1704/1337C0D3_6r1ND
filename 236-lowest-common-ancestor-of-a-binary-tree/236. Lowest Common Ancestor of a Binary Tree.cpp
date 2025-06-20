/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* rec(TreeNode* root, int p, int q){
        if (!root || root->val ==p || root->val ==q) return root;
        auto left = rec(root->left, p, q);
        auto right = rec(root->right, p, q);
        if (left == NULL) return right;
        else if (right == NULL) return left;
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=rec(root, p->val, q->val);
        return ans;
    }
};