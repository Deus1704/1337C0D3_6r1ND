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
    int ht(TreeNode* root){
        if (root== NULL) return 0;
        int lt = ht(root->left);
        int rt = ht(root->right);
        if (lt==-1 || rt==-1) return -1;
        if (abs(lt-rt)>1) return -1;
        return 1+max(lt,rt); 
    }
public:
    bool isBalanced(TreeNode* root) {
        if (ht(root)==-1) return false;
        return true;
    }
};