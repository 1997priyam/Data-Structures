
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
bool isIdentical(Node *,Node *);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     
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
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     
  //  inorder(root);
    //sec tree
     map<int, Node*> mm;
     int nn;
     scanf("%d",&nn);
     struct Node *roott = NULL;
    
     while (nn--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (mm.find(n1) == mm.end())
        {
           parent = new Node(n1);
           mm[n1] = parent;
           if (roott == NULL)
             roott = parent;
        }
        else
           parent = mm[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        mm[n2]  = child;
     }
  
  cout<<isIdentical(root,roott)<<endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
/* Should return true if trees with roots as r1 and 
   r2 are identical */
bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if(r1==NULL && r2==NULL) return true;
    if((r1==NULL && r2!=NULL) || (r2==NULL && r1!=NULL)) return false;
    queue<Node *> q1;
    queue<Node *> q2;
    q1.push(r1);
    q2.push(r2);
    while(q1.size()>0 && q2.size()>0){
        Node *one = q1.front();
        Node *two = q2.front();
        q1.pop();
        q2.pop();
        if(one->data == two->data){
            if((one->left != NULL) && (two->left !=NULL)){
                q1.push(one->left);
                q2.push(two->left);
            }
            else if((one->left == NULL) && (two->left == NULL)){}
            else return false;
            
            if((one->right != NULL) && (two->right !=NULL)){
                q1.push(one->right);
                q2.push(two->right);
            }
            else if((one->right == NULL) && (two->right == NULL)){}
            else return false;
            
        }
        else return false;
    }
    return true;
}