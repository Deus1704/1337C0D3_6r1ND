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
    int leftht(TreeNode* node){
        int ht=0;
        while (node){
            ht++; node = node->left;
        }
        return ht;
    }
    int rightht(TreeNode* node){
        int ht=0;
        while (node){
            ht++; node = node->right;
        }
        return ht;
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lht = leftht(root);
        int rht = rightht(root);
        if (lht == rht) return (1<<lht)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};