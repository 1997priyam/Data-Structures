#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> sort(vector<int> A, vector<int> B){
    vector<int> ans;
    int i = 0, j = 0;
    while(i<A.size() && j<B.size()){
        if(A[i]<=B[j]){
            ans.push_back(A[i]);
            i++;
        }
        else if(A[i]>B[j]){
            ans.push_back(B[j]);
            j++;
        }
    }
    while(i<A.size() || j<B.size()){
        if(i == A.size()){
            ans.push_back(B[j]);
            j++;
        }
        else if(j == B.size()){
                ans.push_back(A[i]);
                i++;
        }
    }
    return ans;
}
int main(){
    vector<int> A = {1,4,6,7,9,22};
    vector<int> B = {2,2,3,4,5,6,7};
    vector<int> ans = sort(A, B);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<", ";
    }
}