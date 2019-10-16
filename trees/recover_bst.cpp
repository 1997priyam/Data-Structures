#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
    
public:
    void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        vector<TreeNode*> vec;
        TreeNode *previous = new TreeNode(INT_MIN);
        traverse(root, &previous, vec);
        int lastIndex = vec.size()-1;
        int temp = vec[0]->val;
        vec[0]->val = vec[lastIndex]->val;
        vec[lastIndex]->val = temp;
    }
    
    void traverse(TreeNode *present, TreeNode **previous, vector<TreeNode*> &vec){
        if(present==NULL) return;
        traverse(present->left, previous, vec);
        if(present->val<(*previous)->val){
            vec.push_back(*previous);
            vec.push_back(present);
        }
        *previous = present;
        traverse(present->right, previous, vec);
    }
};