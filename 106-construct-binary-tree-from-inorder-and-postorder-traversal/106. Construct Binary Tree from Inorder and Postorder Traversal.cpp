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
    TreeNode* BT(map<int,int>&mp,vector<int>& inorder, int inStart, int inEnd ,vector<int>& postorder, int postStart, int postEnd ){
        if (inStart>inEnd || postStart>postEnd) return NULL;
        // cout<<"trying the postEnd="<<postEnd<<endl;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int root_index = mp[root->val];
        int left = root_index - inStart;
        root->left = BT(mp, inorder, inStart, inStart+left-1, postorder, postStart, postStart+left-1);
        root->right = BT(mp, inorder, root_index+1, inEnd, postorder, postStart+left, postEnd-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for (int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root = BT(mp,inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        return root;
    }
};