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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (root == NULL) return ans;
        bool lr=true;
        queue<TreeNode*>q; q.push(root);
        while (!q.empty()){
            vector<int>level(q.size());
            int s = q.size();
            for (int i=0; i<s; i++){
                TreeNode* node = q.front(); q.pop();
                int index = lr? i:s-i-1;
                level[index] = (node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(level);
            lr=!lr;
        }
        return ans;
    }
};