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
    void rec(TreeNode*root, vector<int>&inorderd_traversal){
        if (!root) return;
        if (root->left) rec(root->left, inorderd_traversal);
        inorderd_traversal.push_back(root->val);
        if (root->right) rec(root->right, inorderd_traversal);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return false;
        vector<int>inorderd_traversal;
        rec(root, inorderd_traversal);
        vector<int>temp = inorderd_traversal; sort(temp.begin(), temp.end());
        unordered_set<int>st;
        for (auto &i:inorderd_traversal) st.insert(i);
        if (st.size() != inorderd_traversal.size()) return false; 
        return inorderd_traversal == temp; 
    }
};