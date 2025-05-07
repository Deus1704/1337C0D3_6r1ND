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
        int maxidia(TreeNode* root, int&maxi){
            if (root == NULL) return 0;
            int lt = maxidia(root->left, maxi);
            int rt = maxidia(root->right, maxi);
            maxi = max(maxi, lt+rt);

            return 1+max(lt,rt);
        }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = -1;maxidia(root, maxi);
        return maxi;
    }
};