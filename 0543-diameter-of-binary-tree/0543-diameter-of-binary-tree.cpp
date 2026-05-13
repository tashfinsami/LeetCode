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
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> idx;
        stack<TreeNode*> buffer;
        idx[nullptr] = {0, 0};
        if(root) buffer.push(root);
        while(!buffer.empty()) {
            TreeNode* node = buffer.top();
            if(node->left && !idx.count(node->left)) buffer.push(node->left);
            else if(node->right && !idx.count(node->right)) buffer.push(node->right);
            else {
                TreeNode* cur_node = buffer.top();
                buffer.pop();
                auto [l_depth, l_diameter] = idx[cur_node->left];
                auto [r_depth, r_diameter] = idx[cur_node->right];
                int cur_depth = max(l_depth, r_depth) + 1;
                int cur_diameter = l_depth + r_depth;
                int max_diameter = max(cur_diameter, max(l_diameter, r_diameter));
                idx[cur_node] = {cur_depth, max_diameter};
            }
        }
        return idx[root].second;
    }
};
