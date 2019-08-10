#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>>diagonal(vector<vector<int> > &A) {
    int num = A.size();
    int T = 0;
    int R = num;
    vector<vector<int>> ans;
    for(int i=0; i<R; i++){
        vector<int> arr;
        int W = T;
        int C = i;
        while(W<R && C>=0){
            arr.push_back(A[W][C]);
            W+=1; C-=1;
        }
        ans.push_back(arr);
    }
    for(int j=1; j<R; j++){
        vector<int> arr;
        int W = R-1;
        int C = j;
        while(C<R && W>=0){
            arr.push_back(A[C][W]);
            C+=1; W-=1;
        }
        ans.push_back(arr);
    }
    return ans;
}
int main(){
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans = diagonal(a);
    int num = (a[0].size()*2)-1;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}