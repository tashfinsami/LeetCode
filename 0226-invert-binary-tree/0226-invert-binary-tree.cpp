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
private:
    void dfs(TreeNode* cur) {
        swap(cur->left, cur->right);
        if(cur->left) dfs(cur->left);
        if(cur->right) dfs(cur->right);
        return;
    }
public:
    TreeNode* invertTree(TreeNode* root) { 
        if(!root) return nullptr;
        dfs(root);
        return root;
    }
};
