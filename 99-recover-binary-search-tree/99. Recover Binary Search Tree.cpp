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
    bool first = true;
    void inorder_traversal(TreeNode* root, TreeNode* &prev, vector<TreeNode*>&violations){
        if (!root) return;
        if (root->left) {
            inorder_traversal(root->left, prev, violations);
        }
        if (prev && root->val < prev->val){
            if (first){
                violations.push_back(prev); 
                violations.push_back(root); first = false;
            }else{
                violations.push_back(root);
            }
        }
        prev = root;
        if (root->right) inorder_traversal(root->right, prev, violations);
    }
    void recoverTree(TreeNode* root) {
        if (!root) return;
        TreeNode* prev = NULL;
        vector<TreeNode*>violations;
        inorder_traversal(root, prev, violations);
        // for (auto &i:violations) cout<<i->val<<",";
        if (violations.size() == 2){
            swap(violations[0]->val, violations[1]->val);
        }else if (violations.size() == 3){
            swap(violations[0]->val, violations[2]->val);
        }
    }
};