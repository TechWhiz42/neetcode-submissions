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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;

        q.push(root);
        int level = 0;

        while(!q.empty()){
            int len = q.size();
            res.push_back({});

            for(int i = 0; i<len; i++){
                TreeNode* node = q.front();
                q.pop();

                res[level].push_back(node->val);

                if(node->left!= nullptr)
                    q.push(node->left);
            
                if(node->right != nullptr)    
                    q.push(node->right);
            }
            level++;
        }
        return res;
    }
};
