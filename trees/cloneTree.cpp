#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *random;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    random = NULL;
	}
};
Node *cloneTree(Node *);
int printInorder(Node* a,Node *b)
{
    if ((a==NULL and b==NULL) or (a->random==NULL and b->random==NULL))
        return 1;
    if(a->random->data == b->random->data and printInorder(a->left,b->left) and printInorder(a->right,b->right))
        return 1;
    return false;
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L'){
          parent->left = child;
           m[n2]  = child;
        }
        else if(lr=='R'){
          parent->right = child;
           m[n2]  = child;
        }
        else{
          parent->random = m[n2];
        }
     }
     Node *t = cloneTree(root);
      if(t==root)
        cout<<0<<endl;
     else
     cout<<printInorder(root,t);
     cout<<endl;
  }
  return 0;
}
Node* cloneTree(Node* tree);

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/
/* The function should clone the passed tree and return 
   root of the cloned tree */
Node* cloneTree(Node* tree)
{
    if(tree == NULL) return NULL;
   queue<Node*> q1;
   queue<Node*> q2;
   map<int, Node*> nodeLookup;
   Node *clonedTree;
   clonedTree = new Node(tree->data);
   nodeLookup[clonedTree->data] = clonedTree;
   q1.push(tree);
   q2.push(clonedTree);
   while(!q1.empty() && !q2.empty()){
       Node *orgNode = q1.front();
       Node *clNode = q2.front();
       q1.pop(); q2.pop();
       if(orgNode->left){
           clNode->left = new Node(orgNode->left->data);
           nodeLookup[clNode->left->data] = clNode->left;
           q1.push(orgNode->left);
           q2.push(clNode->left);
       }
       else clNode->left = NULL;
       if(orgNode->right){
           clNode->right = new Node(orgNode->right->data);
           nodeLookup[clNode->right->data] = clNode->right;
           q1.push(orgNode->right);
           q2.push(clNode->right);
       }
       else clNode->right = NULL;
       if(orgNode->random){
            clNode->random = nodeLookup[orgNode->random->data];
       }
   }
   return clonedTree;
}
