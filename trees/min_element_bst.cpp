#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
Node* insert(Node* node, int data) 
{
    
    if(node == NULL) return(new Node(data)); 
    else
    {
        if (data <= node->data)node->left = insert(node->left, data);
        else node->right = insert(node->right, data);
        return node; 
    }
}
int minValue(Node* root);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, tmp;
        cin>>n>>tmp;
        Node* root = NULL;
        root = insert(root, tmp);
        n--;
        while(n--){
            cin>>tmp;
            insert(root, tmp);
        }
        cout<<minValue(root)<<endl;
    }
    return 0;
}

int minValue(Node* root)
{
    if (root==NULL) return -1;
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
    
}