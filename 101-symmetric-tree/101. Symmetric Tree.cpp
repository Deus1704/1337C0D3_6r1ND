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
    bool rec(TreeNode* left, TreeNode* right){
        if (!left || !right) return left==right;
        if (left->val != right->val) return false;

        return rec(left->right, right->left) && rec(left->left, right->right);
    }
    bool isSymmetric(TreeNode* root) {
        // simply try the level order traversal, and the array should be mirror
        return root==NULL||rec(root->left, root->right);
    }
};