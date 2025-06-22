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
       // Stick with the level order traversal
       queue<pair<TreeNode*, int>>q;q.push({root,0});
       long long width=0;
       while (!q.empty()){
            int s = q.size();
            long long mini = q.front().second, first=0, last=0;
            for (int i=0; i<s; i++){
                long long cur_pos = q.front().second-mini;
                auto node = q.front().first; q.pop();
                if (i==0) first = cur_pos;
                if (i==s-1) last = cur_pos;
                if (node->left) q.push({node->left, cur_pos*2+1});
                if (node->right) q.push({node->right, cur_pos*2+2});
            }
            width = max(width, last-first+1);
       }
       return (int)width;
    }
};