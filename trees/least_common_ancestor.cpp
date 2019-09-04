#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;
};
Node * Least_Common_Ancestor(Node *root, Node *a, Node *b){
    if(!root) return;
    while(1){
        if((a->data < root->data && b->data > root->data) || (a->data > root->data && b->data < root->data)){
            return root;
        }
        if(a->data < root->data) root = root->left;
        else root = root->right;
    }
}
int main(){
    // Write the code to create a tree and call this function to get the LCA
     return 0;
 }