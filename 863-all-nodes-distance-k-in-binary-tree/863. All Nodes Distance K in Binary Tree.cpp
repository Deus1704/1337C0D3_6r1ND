/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*>mp;
        queue<TreeNode*>q;q.push(root);
        while (!q.empty()){
            auto parent = q.front(); q.pop();
            if (parent->left) {
                mp[parent->left] = parent;
                q.push(parent->left);
            }
            if (parent->right) {
                mp[parent->right] = parent;
                q.push(parent->right);
            }
        }
        if (k==0) return {target->val};
        vector<int>ans;
        unordered_map<TreeNode*, int>visited;
        q.push(target);int dist=0;visited[target]=1;
        while (!q.empty()){
            int s = q.size();
            for (int i=0; i<s; i++){
                auto node = q.front(); q.pop();
                // move up
                if (mp[node] && !visited[mp[node]]) {
                    q.push(mp[node]);
                    visited[mp[node]]++;
                }
                // move left
                if (node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]++;
                }
                // move right
                if (node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]++;
                }
            }dist++;
            if (dist==k){
                while (!q.empty()){
                    ans.push_back(q.front()->val); q.pop();
                }
            }
        }
        return ans;
    }
};