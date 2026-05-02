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
    void bfs_left_fill(TreeNode* node, queue<int> &qval) {
        node->val = qval.front();
        qval.pop();
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(!qval.empty()) {
                int lval = qval.front();
                qval.pop();
                if(lval == INT_MAX) cur->left = nullptr;
                else {
                    if(!cur->left) cur->left = new TreeNode(lval);
                    else cur->left->val = lval;
                    q.push(cur->left);
                }
            }
            if(!qval.empty()) {
                int rval = qval.front();
                qval.pop();
                if(rval == INT_MAX) cur->right = nullptr;
                else {
                    if(!cur->right) cur->right = new TreeNode(rval);
                    else cur->right->val = rval;
                    q.push(cur->right);
                }
            }
        }
        return;
    }
    void bfs_right_extract(TreeNode* node, queue<int> &qval) {
        qval.push(node->val);
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            //if(!cur->left && !cur->right) continue; 
            if(cur->right){
                qval.push(cur->right->val);
                q.push(cur->right);
            }
            else qval.push(INT_MAX);
            if(cur->left) {
                qval.push(cur->left->val);
                q.push(cur->left);
            }
            else qval.push(INT_MAX);
        }
    }
public:
    TreeNode* invertTree(TreeNode* root) { // without node swapping
        if(!root) return root;
        queue<int> qval;
        bfs_right_extract(root, qval);
        bfs_left_fill(root, qval);
        return root;
    }
};
