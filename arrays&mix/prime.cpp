#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int isPrime(int A) {
    int N = sqrt(A);
    if(A==1) return 1;
    for(int i=2; i<=N; i++){
        if(A%i==0){
            return -1;
        }
    }
    return 1;
}
int main(){
    cout<<"Enter a number: ";
    int n;
    cin>>n;
    cout<<isPrime(n);
}