#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> sort(vector<int> A){
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A.size()-i-1; j++){
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    return A;
}
int main(){
    vector<int> A = {8,5,3,9,4,2,4,7,9};
    vector<int> ans = sort(A);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}