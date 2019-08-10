#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int solve(vector<int> &A) {
    vector<int> ans = A;
    sort(ans.begin(), ans.end());
    int len = ans.size();
    bool flag = false;
    for(int i=0; i<ans.size(); i++){
        len -= 1;
        if(ans[i] == len){
            if(len == 0){
                flag = true;
                break;
            }
            else if(ans[i] != ans[i+1]){
                flag = true;
                break;
            }
            
        }
    }
    if(flag) return 1; else return -1;
}

int main(){
    vector<int> A = {-4, -2, 0, -1, -6};
    cout<<solve(A);
}
