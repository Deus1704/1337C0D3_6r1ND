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
    int widthOfBinaryTree(TreeNode* root) {
       long long ans=0;
       if (!root) return ans;
       queue<pair<TreeNode*, long long>>q; q.push({root,0});
       while (!q.empty()){
            int s = q.size(); long long base = q.front().second, first=0, last=0;
            // ans = max(ans, s);
            for (int i=0; i<s; i++){
                auto [node, pos] = q.front(); q.pop();
                auto normalised_pos = pos-base;
                if (i==0) first = normalised_pos;
                if (i==s-1) last = normalised_pos;
                if (node->left) {q.push({node->left,normalised_pos*2+1});}
                if (node->right) {q.push({node->right,normalised_pos*2+2});}
            }
            ans = max(ans, last-first+1);
       }
       return (int)ans;
    }
};