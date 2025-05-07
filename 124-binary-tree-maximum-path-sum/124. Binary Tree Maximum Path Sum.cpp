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
    int maxipath(TreeNode* root, int&path_sum){
        if (root == NULL) return 0;
        int lt = max(0, maxipath(root->left, path_sum));
        int rt = max(0, maxipath(root->right, path_sum));
        path_sum = max(path_sum, lt+rt+root->val);
        return root->val+max(lt, rt);
    }
public:
    int maxPathSum(TreeNode* root) {
        int path_sum=INT_MIN;
        maxipath(root, path_sum );
        return path_sum;
    }
};