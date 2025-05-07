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
    void pre(TreeNode* root,vector<int>&arr ){
        if (!root) { 
            arr.push_back(INT_MIN); // This so that we can differentiate between the individual points;
            return ;
        }
        arr.push_back(root->val);
        pre(root->left, arr);
        pre(root->right, arr);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Just check the pre-order traversal of both the roots.
        vector<int>ps; pre(p, ps);
        vector<int>qs; pre(q, qs);
        // cout<<"NOw printing p"<<endl; for (auto& i:ps) cout<<i<<","; cout<<endl;
        // cout<<"NOw printing q"<<endl; for (auto& i:qs) cout<<i<<","; cout<<endl;
        return ps==qs;
    }
};