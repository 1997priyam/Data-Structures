#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *leftPtr, *rightPtr;
};

Node* getNewNode(int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->leftPtr = NULL;
    newNode->rightPtr = NULL;
    return newNode;
}

Node * insert(Node *root, int data){
    if(root == NULL){
        root = getNewNode(data);
    }
    else if(data <= root->data){
        root->leftPtr = insert(root->leftPtr, data);
    }
    else{
        root->rightPtr = insert(root->rightPtr, data);
    }
    return root;
}

Node * deleteNode(Node *root, int data){
    if(root == NULL){
        cout<<"Not found";
    }
    else if(data < root->data){
        root->leftPtr = deleteNode(root->leftPtr, data);
    }
    else if(data > root->data){
        root->rightPtr = deleteNode(root->rightPtr, data);
    }
    else{
        //Found the node with data
        if(root->leftPtr && root->rightPtr){
            Node *temp = findMin(root->rightPtr);
            root->data = temp->data;
            root->rightPtr = deleteNode(root->rightPtr, root->data);
        }
        else if(!root->leftPtr){
            Node *temp = root;
            root = root->rightPtr;
            delete(temp);
        }
        else{
            Node *temp = root;
            root = root->leftPtr;
            delete(temp);
        }
    }
    return root;
}

Node * findMin(Node *root){
    if(root == NULL) return;
    while(root->leftPtr != NULL){
        root = root->leftPtr;
    }
    return root;
}

int main(){
    Node *root = NULL;
    int x;
    cout<<"Enter 10 numbers to be added in the tree: ";
    for(int i = 0; i<10; i++){
        cin>>x;
        root = insert(root, x);
        cout<<"Root: "<<root<<endl;
        cout<<"Left: "<<root->leftPtr<<endl;
        cout<<"Right: "<<root->rightPtr<<endl;
    }
    return 0;
}