#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
void print(vector<int> arr){
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void space(int n){
    for(int i=0; i<n; i++){
        cout<<" ";
    }
}
void pascal_triangle(int n){
    vector<int> prev_arr;
    for(int i=0; i<n; i++){
        vector<int> arr;
        for(int j=0; j<=i; j++){
            if(j==0 || j==i){
                arr.push_back(1);
            }
            else{
                arr.push_back(prev_arr[j-1]+prev_arr[j]);
            }
        }
        space(n-i);
        print(arr);
        prev_arr = arr;
    }
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    pascal_triangle(n);
}