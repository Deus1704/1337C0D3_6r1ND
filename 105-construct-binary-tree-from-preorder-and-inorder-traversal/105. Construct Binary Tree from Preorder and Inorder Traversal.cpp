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
    TreeNode* BT(map<int,int>&mp, vector<int>& preorder, int preStart, int preEnd,vector<int>& inorder,int inStart, int inEnd){
        if (preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int root_index = mp[root->val];
        int left_array = root_index - inStart;

        root->left = BT(mp, preorder, preStart+1, preStart+left_array, inorder, inStart, root_index-1);
        root->right = BT(mp, preorder, preStart+1+left_array, preEnd, inorder, root_index+1, inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for (int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root = BT(mp,preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);

        return root;
    }
};