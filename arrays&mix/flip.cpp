#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector <int> flip(string A) {
    int start = 1;
    int end = 1;
    int beg = 1;
    int max_so_far = INT_MIN;
    int max_here = 0;
    bool flag = true;
    int n = A.size();
    int *arr = new int[n];
    for(int j=0; j<n; j++){
        if(A[j]=='0'){
            flag = false;
            break;
        }
    }
    if(flag){
        vector<int> ans;
        return ans;
    }
    for(int i=0; i<n; i++){
        if(A[i]=='0'){
            max_here += 1; 
        }
        else{
            max_here -= 1;
        }
        if(max_here < 0){
            max_here = 0;
            beg = i+2;
            }  
        if(max_here > max_so_far){
            max_so_far = max_here;
            start = beg;
            end = i+1;
        }
    }
    vector<int> ans;
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}

int main (){
    vector<int> a = flip("01111111111100");
    for (int i = 0 ; i < 2 ;i ++)
        cout << a[i]<< " ";
    cout<<endl;
}