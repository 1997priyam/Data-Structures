#include<iostream>

using namespace std;

#define MAX_SIZE 100
int A[MAX_SIZE];
int top = -1;

void push(int num){
    if(top == MAX_SIZE){
        cout<<"Error: Stackoverflow."<<endl;
    }
    else{
        A[++top] = num;
    }
}

int pop(){
    if(top == -1){
        cout<<"Error: Stackunderflow."<<endl;
    }
    else{
        return A[top--];
    }
}

int topp(){
    if(top == -1){
        cout<<"Error: Stackunderflow."<<endl;
    }
    else{
        return A[top];
    }
}

bool isEmpty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    push(23);
int i = pop();
cout<<i<<endl;
}