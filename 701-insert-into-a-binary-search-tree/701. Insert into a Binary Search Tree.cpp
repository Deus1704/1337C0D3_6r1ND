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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* fake = root;
        TreeNode* prev = nullptr;
        TreeNode* new_ptr = new TreeNode(val);
        if (!fake) return new_ptr;
        while (fake) {
            prev = fake;
            if (val < fake->val) {
                fake = fake->left;
            } else {
                fake = fake->right;
            }
        }
        if (val < prev->val) {
            prev->left = new_ptr;
        } else {
            prev->right = new_ptr;
        }
        return root;
    }
};
