#include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

class vecto{
    int size;
    int count;
    int* arr;
    public:
        vecto(){
            count=0;
            size=1;
            arr = new int[size];
        }
        void push(int num){
            if(size==count){
                size *= 2;
                int* arr2 = new int[size];
                for(int i=0; i<count; i++){
                    arr2[i] = arr[i];
                }
                arr = arr2;
            }
            arr[count++] = num;
        }
        int pop(){
            return arr[--count];
        }
};

int main(){
    vecto *A = new vecto();
    A->push(1);
    A->push(2);
    A->push(3);
    A->push(4);
    cout<<A->pop()<<" "<<A->pop()<<" "<<A->pop();

}
