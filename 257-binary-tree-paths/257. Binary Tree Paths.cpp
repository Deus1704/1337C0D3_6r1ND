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
    void rec(TreeNode* root,vector<vector<int>>&ar,vector<int>&temp){
        if (!root) return ;
        temp.push_back(root->val);
        if (!root->left && !root->right){
            ar.push_back(temp);
        }if(root->left){
            rec(root->left, ar, temp);
        }if(root->right){
            rec(root->right, ar, temp);
        }
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        vector<vector<int>>ar;vector<int>temp;
        rec(root, ar, temp);
        for (auto &i:ar){
            string s="";
            // cout<<"now printing i=";
            for (auto &j:i) s+=to_string(j)+"->";
            int tem = s.size();
            ans.push_back(s.substr(0,tem-2));
        }
        return ans;
    }
};