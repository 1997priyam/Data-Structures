/* Bosky often helps his younger brother Nitin with his home work and also clears his doubts.

Today, Nitin learned about proper fractions. He went a step forward and tried to represent the same proper 
fraction in its decimal form, but runs into problems. He now seeks help from his brother Bosky.

Nitin is a very sincere learner, thus he wants his brother to help him but doesn't want him to completely 
solve the problem. He goes to his brother Bosky and asks him to help him wherever he gets stuck while 
representing the proper fraction in decimal expansion by telling the next digit in the decimal expansion.

Though Bosky is a bit busy today with his school project, he doesn't want to disappoint his brother. 
He is familiar with your brilliant programming skills and asks you to create a program to help his brother, 
which can output R  digit in the decimal expansion for a given proper fraction .

Input:

Input will contain a number T denoting the number of test cases.

Then T test cases follow, each one consisting 3 integers N D R where N and D are numerator and denominator respectively.

Output:

For each test case, output a single integer representing R  digit from the left in the decimal expansion.

NOTE: The number is a proper fraction, hence the counting will always start after the decimal place. 
For eg. fraction  can be written as  so its first digit is 5 and all the digits after 5 are 0.

SAMPLE INPUT 
4
1 2 1
1 2 2
1 2 20
1234 12345 123

SAMPLE OUTPUT 
5
0
0
7

/*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int get_output(int N, int D, int R){
    int rem = N%D;
    for(int i=R; i>1; i--){
        rem = (rem*10) % D;
    }
    return (rem*10)/D;
}

int main(){
    int T;
    cin>>T;
    int N,D,R;
    for(int i=0; i<T; i++){
        cin>>N>>D>>R;
        cout<<get_output(N, D, R)<<endl;
    }
    return 0;
}
