#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

 int prettyPrint(int A) {
    int size = (A*2)-1;
    int ans[size][size];
    for(int i=0; i<A; i++){
        for(int j=i; j<size-i; j++){
            ans[i][j] = A-i;
        }
        for(int j=i; j<size-i; j++){
            ans[j][size-i-1] = A-i;
        }
        for(int j=i; j<size-i; j++){
            ans[size-i-1][j] = A-i;
        }
        for(int j=i; j<size-i; j++){
            ans[j][i] = A-i;
        }
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
}
}

int main(){
    cout<<"Enter the size: ";
    int n;
    cin>>n;
int a = prettyPrint(n);

}