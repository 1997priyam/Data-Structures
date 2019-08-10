#include<iostream>
using namespace std;

int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}
int main(){
    cout<<"Enter a number: ";
    int n;
    cin>>n;
    cout<<"Answer: "<<factorial(n);
    return 0;
}