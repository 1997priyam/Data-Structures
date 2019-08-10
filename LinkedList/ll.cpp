#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
void insertAtN(int data, int pos){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    Node* temp = head;
    for(int i=0; i<pos-2; i++){
        if(temp == NULL){
            cout<<"Invalid position."<<endl;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int deleteNthNode(int n){
    Node* temp = head;
    for(int i=0; i<n-2; i++){
        if(temp == NULL){
            cout<<"Deletion not possible."<<endl;
        }
        temp = temp->next;
    }
    Node* del = temp->next;
    temp->next = (temp->next)->next;
    int data = del->data;
    free(del);
    return data;
}

int main(){
    Node* temp = new Node();
    temp -> data = 50;
    temp -> next = NULL;
    head = temp;
    Node* temp1 = head;
    insertAtN(34, 2);
    insertAtN(33, 2);
    insertAtN(32, 2);
    insertAtN(31, 2);
    int dele = deleteNthNode(4);
    cout<<"Deleted: "<<dele<<endl;
    while(temp1 != NULL){
        cout<<"DATA: "<<temp1->data<<endl;
        temp1 = temp1->next;
    }
}