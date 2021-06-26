//User function Template for C++


struct Node {
    int data;
    Node* left;
    Node* right;
};


#include <vector>

vector<int> preOrder(Node* root)
{
    //code here
    vector<int> ans;
    if (root == NULL) ans;
    
    stack<Node*> st;
    st.push(root);
    
    while(!st.empty()) {
        Node* current = st.top();
        st.pop();
        ans.push_back(current->data);
        if(current->right) st.push(current->right);
        if(current->left) st.push(current->left);
    }
    return ans;
}