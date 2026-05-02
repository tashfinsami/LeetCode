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
    TreeNode* invertTree(TreeNode* root) { 
        if(!root) return nullptr;
        queue<TreeNode*> buffer;
        buffer.push(root);
        while(!buffer.empty()) {
            TreeNode* cur = buffer.front();
            buffer.pop();
            swap(cur->left, cur->right);
            if(cur->left) buffer.push(cur->left);
            if(cur->right) buffer.push(cur->right);
        }
        return root;
    }
};
