/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

*/



#include <iostream>
#include <bits/stdc++.h>


using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag = true;
        stack<TreeNode *> st1, st2;
        if(p!=NULL && q!=NULL){
            st1.push(p);
            st2.push(q);
        }else if(p==NULL && q==NULL){
            return true;
        }else if(p || q){
            return false;
        }
        
        while(!st1.empty() && !st2.empty()){
            TreeNode *node1 = st1.top();
            TreeNode *node2 = st2.top();
            st1.pop();
            st2.pop();
            if(node1->val != node2->val){
                flag = false;
                break;
            }
            if(node1->left && node2->left){
                st1.push(node1->left);
                st2.push(node2->left);
            }
            else if(!node1->left && !node2->left){
                
            }
            else{
                flag = false;
                break;
            }
            
            if(node1->right && node2->right){
                st1.push(node1->right);
                st2.push(node2->right);
            }
            else if(!node1->right && !node2->right){
                
            }
            else{
                flag = false;
                break;
            }
        }
        
        if(st1.empty() && st2.empty() && flag) return true;
        return false;
    }
};