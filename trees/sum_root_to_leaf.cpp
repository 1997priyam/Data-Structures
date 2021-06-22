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
    int res;
public:
    int sumNumbers(TreeNode* root) {
        res = 0;
        solve(root, 0);
        return res;
    }
    
    void solve(TreeNode *root, int sum) {
        if(root == NULL) return;
        sum = (sum * 10) + root->val;
        if(!root->left && !root->right) {
            res += sum;
        }
        solve(root->left, sum);
        solve(root->right, sum);
        sum = sum/10;
        
    }
};