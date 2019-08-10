#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool hotel(vector<int> arrive, vector<int> depart, int K) {
    int i = 0, j = 0;
    vector<int> ans;
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    cout<<"Arrive: ";
    for(int i=0; i<arrive.size(); i++){
        
        cout<<arrive[i]<<" ";
    }
    cout<<"Depart: ";
    for(int i=0; i<depart.size(); i++){
        
        cout<<depart[i]<<" ";
    }
    while(i<arrive.size() && j<depart.size()){
        if(arrive[i]<depart[j]){
            ans.push_back(0);
            i++;
        }
        else if(arrive[i]>=depart[j]){
            ans.push_back(1);
            j++;
        }
    }
    while(i<arrive.size() || j<depart.size()){
        if(i == arrive.size()){
            ans.push_back(1);
            j++;
        }
        else if(j == depart.size()){
                ans.push_back(0);
                i++;
        }
    }
    cout<<"ANSWER: ";
    cout<<"Ans size: "<<ans.size();
    for(int i=0; i<ans.size(); i++){
        
        cout<<ans[i]<<" ";
    }
    for(int i=0; i<ans.size(); i++){
        if(ans[i] == 0) K--;
        else K++;
        if(K<0) return false;
    }
    return true;
}
int main(){
    vector<int> arr = {13, 14, 36, 19, 44, 1, 45, 4, 48, 23, 32, 16, 37, 44, 47, 28, 8, 47, 4, 31, 25, 48, 49, 12, 7, 8 };
    vector<int> dept = {28, 27, 61, 34, 73, 18, 50, 5, 86, 28, 34, 32, 75, 45, 68, 65, 35, 91, 13, 76, 60, 90, 67, 22, 51, 53};
    int rooms = 23;
    bool a = hotel(arr, dept, rooms);
    cout<<"Possible ? "<<a;
}