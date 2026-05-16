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
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left == INT_MAX || left - right > 1 || left - right < -1) return INT_MAX;
        else return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(dfs(root) == INT_MAX) return false;
        else return true;
    }
};
