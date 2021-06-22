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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return hasPath(root, targetSum, 0);
    }
    
    bool hasPath(TreeNode* root, int targetSum, int sum) {
        if(root == NULL) return false;
        sum+=root->val;
        if(root->left == NULL && root->right == NULL) {
            if(targetSum == sum) return true;
            else return false;
        }
        return hasPath(root->left, targetSum, sum) || hasPath(root->right, targetSum, sum);
    }
};