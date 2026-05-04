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
    int rdepth(TreeNode* node) {
        if(!node) return 0;
        return 1 + max(rdepth(node->left), rdepth(node->right));
    }
    int ldepth(TreeNode* node) {
        if(!node) return 0;
        return 1 + max(ldepth(node->left), ldepth(node->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> buffer;
        buffer.push(root);
        int diameter = 0;
        while(!buffer.empty()) {
            TreeNode* cur = buffer.front();
            buffer.pop();
            int lcount = ldepth(cur->left);
            int rcount = rdepth(cur->right);
            diameter = max(diameter, lcount + rcount);
            if(cur->left) buffer.push(cur->left);
            if(cur->right) buffer.push(cur->right);
        }
        return diameter;
    }
};
