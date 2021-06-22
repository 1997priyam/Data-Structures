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
    int minDepthRes = INT_MAX;
public:
    int minDepth(TreeNode* root) {
        solve(root, 0);
        if(!root) return 0;
        return minDepthRes;
    }
    
    void solve(TreeNode *root, int depth) {
        if(root==NULL) return;
        depth++;
        if(!root->left && !root->right) {
            minDepthRes = min(minDepthRes, depth);
        }
        solve(root->left, depth);
        solve(root->right, depth);
        depth--;
    }
};