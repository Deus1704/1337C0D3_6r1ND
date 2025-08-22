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
class BSTIterator {
public:
    void rec(TreeNode* root, vector<int>&inorderd_traversal){
        if (!root) return;
        if (root->left) rec(root->left, inorderd_traversal);
        inorderd_traversal.push_back(root->val);
        if (root->right) rec(root->right, inorderd_traversal);
    }
    int ptr;
    vector<int>inorderd_traversal;
    BSTIterator(TreeNode* root) {
        auto temp = root;
        rec(root, inorderd_traversal);
        ptr = 0;
    }
    
    int next() {
        if (ptr < inorderd_traversal.size()){
            int to_return = inorderd_traversal[ptr];
            ptr++;
            return to_return;
        }else return -1;
    }
    
    bool hasNext() {
        return (ptr<inorderd_traversal.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */