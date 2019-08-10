#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int maxSpecialProduct(vector<int> &A) {
    int maxprod = INT_MIN;
    for(int i=0; i<A.size(); i++){
        int lsv = 0;
        int rsv = 0;
        for(int j=i-1; j>=0; j--){
            if(A[j]>A[i]){
                lsv = j;
                break;
            }
        }
        for(int k=i+1; k<A.size();k++){
            if(A[k]>A[i]){
                rsv = k;
                break;
            }
        }
        int max = lsv*rsv;
        if(max>maxprod){
            maxprod = max;
        }
    }
    return maxprod;
}
int main(){
    vector<int> A = {3,4,5,6,1,2,3,7,8,42,6,98,2};
    int ans = maxSpecialProduct(A);
    cout<<"Answer: "<<ans;
}