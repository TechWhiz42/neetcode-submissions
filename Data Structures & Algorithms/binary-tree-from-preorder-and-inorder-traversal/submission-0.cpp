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
    int preIdx = 0;
    unordered_map<int,int> indices;

    TreeNode* build(vector<int>& preorder, int l, int r){
        if(l>r) return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = indices[rootVal];
        root->left = build(preorder,l, mid-1);
        root->right = build(preorder, mid+1, r);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i =0; i<inorder.size();i++){
            indices[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size()-1);
    }
};
