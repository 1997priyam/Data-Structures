#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> maxset(vector<int> &A) {
    long max_so_far = 0;
    long max_here = 0;
    long beg = 0;
    int start = 0;
    int end = 0;
    bool flag = true;
    vector<int> ans;
    for(int j=0; j<A.size(); j++){
        if(A[j]>=0){
            flag = false;
            break;
        }
    }
    if(flag){
        return ans;
    }
    for(int i=0; i<A.size(); i++){
        if(A[i] < 0){
            max_here = -1;
            beg = i+1;
        }
        else{
            max_here += A[i]+1;
        }
        if(max_here == max_so_far && A[i] >= 0){
            end = i;
        }
        if(max_here > max_so_far){
            max_so_far = max_here;
            start = beg;
            end = i;
        }
    }
    for(int j=start; j<=end; j++){
        ans.push_back(A[j]);
    }
    return ans;
    
}
int main(){
    vector<int> q = {1,2,3,4,3,-8,-6,1,1,1,1,1,1};
    vector<int> ans = maxset(q);
    for(int j=0; j<ans.size(); j++){
        cout<<ans[j]<<" ";
    }
    
    
}