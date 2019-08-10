#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
vector<int> allFactors(int A) {
    vector<int> ans;
    int N = sqrt(A);
    cout<<"N is "<<N<<endl;
    for(int i=1; i<=N; i++){
        if(A%i == 0){
            ans.push_back(i);
            if(i!=A && A/i != i){
            ans.push_back(A/i);
        }
        }
        
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main(){
    cout<<"Enter a number: ";
    int n;
    cin>>n;
    vector<int> ans = allFactors(n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}