#include<iostream>

using namespace std;

#define MAX_SIZE 100
int A[MAX_SIZE];
int front = -1;
int rear = -1;

bool isFull(){
    if(rear == MAX_SIZE-1) return true;
    else return false;
}

void enqueue(int data){
    if(isFull()) return; 
    else if(isEmpty()){
        front = 0;
        rear = 0;
    }
    else rear = rear+1;
    A[rear] = data;
}

int dequeue(){
    if(isEmpty()) return;
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else front += 1;
}

bool isEmpty(){
    if(front==-1 && rear==-1) return true;
    else return false;
}

int frontt(){
    if(isEmpty){
        return;
    }
    else return A[front];
}

void main(){

}