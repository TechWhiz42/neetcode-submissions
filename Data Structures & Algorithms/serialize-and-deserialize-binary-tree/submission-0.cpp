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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(root == nullptr){
            return "#,";
        }

        return to_string(root->val) + "," +
                serialize(root->left) + 
                serialize(root->right);
    }
    TreeNode* build(vector<string>& nodes, int& idx) {
        if (nodes[idx] == "#") {
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[idx++]));
        root->left = build(nodes, idx);
        root->right = build(nodes, idx);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string token;

        for(char c: data){
            if(c == ','){
                nodes.push_back(token);
                token.clear();
            } else {
                token += c;
            }
        }
        int idx = 0;
        return build(nodes, idx);
    }
};