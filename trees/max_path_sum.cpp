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
    int maxAns = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return maxAns;

        return max(maxAns, dfs(root));
    }
    int dfs(TreeNode* root) {
        if(!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        left = max(0, left);
        right = max(0, right);
        
        maxAns = max(maxAns, left+right+root->val);
        
        return max(left, right) + root->val;
    }
};