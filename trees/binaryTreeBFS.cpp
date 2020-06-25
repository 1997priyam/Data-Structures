#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        vector<int> level;
        while(q.empty() != true) {
            TreeNode *node = q.front();
            q.pop();
            if(node == nullptr){
                if(level.size() == 0) break;
                ans.push_back(level);
                level.clear();
                q.push(nullptr);
                continue;
            }
            level.push_back(node->val);
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
        }
        return ans;
    }
};