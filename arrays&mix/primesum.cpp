#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isPrime(int A) {
    int N = sqrt(A);
    if(A==1) return 1;
    for(int i=2; i<=N; i++){
        if(A%i==0){
            return 0;
        }
    }
    return 1;
}

vector<int> primesum(int A) {
    vector<int> ans;
    for(int i=1; i<=A/2; i++){
        if(isPrime(i) && isPrime(A-i)){
            ans.push_back(i);
            ans.push_back(A-i);
            return ans;

        }
    }
}


int main(){
    cout<<"Enter a number: ";
    int n;
    cin>>n;
    vector<int> ans = primesum(n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}