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
        int left_depth = left.first;
        int right_depth = right.first;
        int cur_depth = max(left_depth, right_depth) + 1;
        int cur_diameter = left_depth + right_depth;
        int left_diameter = left.second;
        int right_diameter = right.second;
        return {cur_depth, max(cur_diameter, max(left_diameter, right_diameter))};
        //return {max(left.first, right.first) + 1, 
        //max(left.first + right.first, max(left.second, right.second))};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> res = func(root);
        return res.second;
    }
};
