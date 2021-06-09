/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        Node *prev = NULL;
        while(!q.empty()) {
            Node * node = q.front();
            q.pop();
            if(node) {
                if(prev == NULL) prev = node;
                else {
                    prev->next = node;
                    prev = prev->next;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            } else {
                prev->next = NULL;
                prev = NULL;
                if(q.size() > 0) q.push(NULL);
            }
        }
        return root;
    }
};