// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

// A leaf is a node with no children.
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
    vector<vector<int>> ans;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs_td(root, targetSum, path, 0);
        return this->ans;
    }
    
    void dfs_td(TreeNode* root, int targetSum, vector<int> path, int currentSum) {
        if(root == nullptr) return;

        currentSum += root->val;
        path.push_back(root->val);
        if(currentSum == targetSum && !root->left && !root->right) {
            this->ans.push_back(path);
        }
        
        dfs_td(root->left, targetSum, path, currentSum);
        dfs_td(root->right, targetSum, path, currentSum);
    }
};