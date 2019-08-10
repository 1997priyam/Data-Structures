#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* head = NULL;
Node* getnewNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtHead(int data){
    Node* newNode = getnewNode(data);
    if(head==NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void insertAtTail(int data){
    Node* newNode = getnewNode(data);
    if(head==NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void insertAtN(int data, int pos){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    Node* temp = head;
    for(int i=0; i<pos-2; i++){
        if(temp == NULL){
            cout<<"Invalid position."<<endl;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    (temp->next)->prev = newNode;
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
    (temp->next)->prev = temp;
    int data = del->data;
    free(del);
    return data;
}


void forwardPrint(){
    Node* temp = head;
    cout<<"Forward: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void reversePrint(){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    cout<<"Reverse: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

int main(){
insertAtHead(10);
insertAtHead(20);
insertAtHead(30);
insertAtHead(40);
insertAtHead(50);
insertAtHead(60);
insertAtHead(70);
insertAtN(11, 2);
insertAtN(22, 3);
insertAtTail(1);
insertAtTail(2);
insertAtTail(3);
insertAtTail(4);
int data = deleteNthNode(4);
cout<<"Deleted data: "<<data<<endl;
forwardPrint();
reversePrint();
}