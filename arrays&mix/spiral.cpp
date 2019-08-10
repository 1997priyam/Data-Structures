#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<int>> generateMatrix(int A) {
    int T = 0; int B = A-1; int L = 0; int R = A-1; int DIR = 0;
    int sq = A*A; int count = 1;
    vector<vector<int>> ans(A, vector<int> (A));
    while(L<=R && T<=B && count<=sq){
        if(DIR==0){
            for(int k=L; k<=R; k++){
                ans[T][k] = count;
                count++;
            }
            T++;
        }
        if(DIR==1){
            for(int k=T; k<=B; k++){
                ans[k][R] = count;
                count++;
            }
            R--;
        }
        if(DIR==2){
            for(int k=R; k>=L; k--){
                ans[B][k] = count;
                count++;
            }
            B--;
        }
        if(DIR==3){
            for(int k=B; k>=T; k--){
                ans[k][L] = count;
                count++;
            }
            L++;
        }
        DIR = (DIR+1)%4;
    }
    return ans;
}

int main(){
    int A = 4;
vector<vector<int>> ans(A, vector<int> (A));
ans = generateMatrix(A);
for(int i=0; i<A; i++){
    for(int j=0; j<A; j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<""<<endl;
}
}