#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> wave(vector<int> &A) {
   vector<int> B = A;
    sort(B.begin(), B.end());
    int len = B.size()/2;
    int index = 0;
    cout<<"LEn: "<<len<<endl;
    for(int i=0; i<len; i++){
        int temp = B[index+1];
        B[index+1] = B[index];
        B[index] = temp;
        index += 2;
    }
    return B;
}

int main(){
vector<int> A = {1,2,3,4,5,6,7,8,9, 10};
vector<int> ans = wave(A);
for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
}
}