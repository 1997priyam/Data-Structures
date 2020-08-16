#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data): data(data), next(nullptr) {}
};

class LinkedList {
    private:
        Node* head;

        Node* getNewNode(int data) {
            Node* node = new Node(data);
            return node;
        }
        
    public:
        LinkedList(): head(nullptr) {}

        void insertNode(int data) {
            Node* newNode = getNewNode(data);
            if (this->head == nullptr) {
                head = newNode;
                return;
            }
            Node* temp = this->head;
            Node* currentNode;
            while(temp != nullptr) {
                currentNode = temp;
                temp = temp->next;
            }
            currentNode->next = newNode;
        }

        void print() {
            if (this->head == nullptr) {
                cout << "Empty List!" << endl;
            }
            Node* temp = this->head;
            while(temp != nullptr) {
                cout << temp->data << " --> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
};

int main() {
    LinkedList ll = LinkedList();
    ll.insertNode(10);
    ll.insertNode(20);
    ll.insertNode(30);
    ll.insertNode(40);
    ll.insertNode(50);
    ll.print();
}