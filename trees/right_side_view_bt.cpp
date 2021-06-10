#include<vector>
#include<queue>

//  Definition for a binary tree node.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        TreeNode* prev;
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty()) {
            TreeNode * current = q.front();
            q.pop();
            if(!current) {
                ans.push_back(prev->val);
                if(q.size() > 0) q.push(nullptr);
            } else {
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                prev = current;
            }
        }
        return ans;
    }
};