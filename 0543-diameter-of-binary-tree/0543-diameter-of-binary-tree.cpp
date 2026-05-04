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
    pair<int, int> func(TreeNode* node) {
        if(!node) return {0, 0};
        pair<int, int> left = func(node->left);
        pair<int, int> right = func(node->right);
        int depth = max(left.first + 1, right.first + 1);
        int diameter = left.first + right.first;
        return {depth, max(diameter, max(left.second, right.second))};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> res = func(root);
        return res.second;
    }
};
