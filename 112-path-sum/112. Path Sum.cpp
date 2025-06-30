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
    bool rec(TreeNode* root, int ts, int cursum){
        if (root->left==nullptr && root->right==nullptr){
            // i.e reached the leaf node, check if the sum matches the target
            if (cursum+root->val == ts) return true;
            return false;
        }
        if ( (root->left && rec(root->left, ts, cursum+root->val)) || (root->right && rec(root->right, ts, cursum+root->val))){
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int ts) {
        if (!root) return false;
        auto cur = root;
        if (rec(cur, ts, 0)) return true;
        return false;
    }
};