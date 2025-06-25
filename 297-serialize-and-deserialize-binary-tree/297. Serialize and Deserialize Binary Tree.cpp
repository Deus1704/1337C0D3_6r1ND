/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <bits/stdc++.h>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string ser="";
        queue<TreeNode*>q;q.push(root);
        while (!q.empty()){
            auto node = q.front(); q.pop();
            if (node == NULL) ser+="null,";
            else ser.append(to_string(node->val)+",");
            if (node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        // cout<<"generated ser="<<ser<<endl;
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size()==0) return NULL;
        stringstream s(data);
        // cout<<"GOt data ="<<data<<endl;
        string cha;
        getline(s, cha, ',');
        // vector<int>sq;
        // while(getline(s,cha,',')){
        //     // cout<<"tf is cha="<<cha<<endl;
        //     if (cha=="null") sq.push_back(1e9);
        //     else sq.push_back(stoi(cha));
        // }
        // for (auto &i:sq) cout<<i<<","; cout<<endl;
        TreeNode* root = new TreeNode(stoi(cha));
        queue<TreeNode*>q;q.push(root);
        while (!q.empty()){
            auto node = q.front(); q.pop();
            getline(s, cha, ',');
            if (cha == "null"){
                node->left = NULL;
            }else {
                auto Leaf = new TreeNode(stoi(cha));
                node->left = Leaf; q.push(Leaf);
            }
            getline(s, cha, ',');
            if (cha == "null"){
                node->right = NULL;
            }else {
                auto Leaf = new TreeNode(stoi(cha));
                node->right = Leaf; q.push(Leaf);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));