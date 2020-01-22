/*
Mattey has an assignment that he should submit tomorrow. The assignment has one question which asks to write a program to multiply two numbers without using ''* operator. As Mattey finds no interest in this subject, he never listens to classes and so do not know about shift operators.

He comes to you to learn about this topic. You can explain in any manner you wish. But for this question, given N and M, write an equation using left shift operators whose result will be equal to the product .

Input :
First line has T denoting number of test cases.
Next T lines has two integers .

Output :
For each test case print an equation resembling "(N<<p1) + (N <<p2) + ... + (N <<pk)" (without quotes) where  ≥  ≥ ... ≥  and k is minimum.

SAMPLE INPUT 
2
2 1
2 3

SAMPLE OUTPUT 
(2<<0)
(2<<1) + (2<<0)

/*/

// The last 3 test cases didn't pass.

#include <iostream>

using namespace std;

void get_output(int n, int m){
    long long ans = 0, count = 0;
    string pans = "";
    while(m){
        if(m%2 == 1){
            pans = "("+to_string(n)+"<<"+to_string(count)+") + " + pans;
        }
        count++;
        m = m/2;
    }
    for(long long i=0; i<pans.size()-2; i++){
        cout<<pans[i];
    }
    cout<<endl;
}

int main(){
    unsigned long int N, n, m;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>n>>m;
        get_output(n, m);
    }
    return 0;
}