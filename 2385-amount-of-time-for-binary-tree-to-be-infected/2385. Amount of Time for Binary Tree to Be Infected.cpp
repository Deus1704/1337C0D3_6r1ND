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
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>q;q.push(root);
        TreeNode* ptr = root->val==start? root : nullptr;
        while (!q.empty()){
            int s = q.size();
            for (int i=0; i<s; i++){
                auto node = q.front(); q.pop();
                if (node->val == start) ptr = node;
                if (node->left){
                    mp[node->left]=node;q.push(node->left);
                }
                if (node->right){
                    mp[node->right]=node;q.push(node->right);
                }
            }
        }
        int time=0;q.push(ptr);
        map<TreeNode*,int> visited; visited[ptr]=1;
        while (!q.empty()){
            int s = q.size();
            for (int i=0; i<s; i++){
                auto node = q.front(); q.pop();
                // move up;
                if (mp[node] && !visited[mp[node]]){
                    visited[mp[node]]++;
                    q.push(mp[node]);
                }
                // move left;
                if (node->left && !visited[node->left]){
                    visited[node->left]++;
                    q.push(node->left);
                }
                // move right;
                if (node->right && !visited[node->right]){
                    visited[node->right]++;
                    q.push(node->right);
                }
            }
            time++;
        }
        return time-1;
    }
};