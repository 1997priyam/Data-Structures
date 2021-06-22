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
    bool res = true;
public:
    bool isBalanced(TreeNode* root) {
        solve(root);
        return res;
    }
    
    int solve(TreeNode* root) {
        if(root == NULL) return 0;
        
        int l = solve(root->left) + 1;
        int r = solve(root->right) + 1;
        
        if(l-r < -1 || l-r > 1) res = false;
        return max(l, r);
        
    }
};