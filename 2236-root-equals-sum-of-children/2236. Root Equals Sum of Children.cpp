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
    bool checkTree(TreeNode* root) {
        if (!root) return true;
        if (checkTree(root->left) && checkTree(root->right) ){
            // i.e the left and right boht are true;
            // then check if the current is also matching the same property;
            int child_worth=0;
            if (root->left) child_worth+=root->left->val;
            if (root->right) child_worth+=root->right->val;
            if (child_worth == root->val) return true;
            else if (child_worth ==0 && (!root->left && !root->right)) return true; // since need to cater the leaf nodes
            return false;
        }else return false;
    }
};