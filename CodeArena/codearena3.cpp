/*
Here is another task for you, prepared by Monk himself. So, this is how it goes :

Given an integer array A of size N, Monk needs you to answer T queries for him. In each query, 
he gives you 2 integers P and Q. In response to each of these queries, 
you need to tell Monk the count of numbers in array A. that are either divisible by P, Q, or both.

Can you cope with this ?

Input Format :

The first line contains a single integer N denoting the size of array A. 
The next line contains N space separated integers, where the  integer denotes .

The next line contains a single integer T denoting the number of queries Monk poses to you. 
Each of the next T lines contains 2 space separated integers P and Q.

Output Format :

For each query, print the answer on a new line.

SAMPLE INPUT 
6
2 3 5 7 4 9
2
4 5
3 7

SAMPLE OUTPUT 
2
3

Explanation
For the  query in the  sample, the numbers that form a part of the count are 4 and 5,
present at indices 5 and 3 respectively.
//*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int get_output(vector<int> &ans, int P, int Q, int max){
    int result = 0;
    if(P<=max){     // If the requested number is grerater than max then do nothing as its multiple won't exist
        result+=ans[P];
    }
    if(Q<=max){
        result+=ans[Q];
    }
    return result;
}

void create_sieve(vector<int> &arr, vector<int> &ans, vector<int> &count, int max){
    for(int num: arr){          // Updating count by Entering the number of times a number appeared in the actual array
        count[num]++;
    }

    for(int i=1; i<max+1; i++){     // Creating the sieve here, Iterating upto max value and for each value checking its 
        for(int j=i; j<max+1; j+=i){    // maximum possible multiples upto max and marking their count in ans.
            ans[i] += count[j];
        }
    }
}

int main(){
    int N, num;
    vector<int> arr;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num;
        arr.push_back(num);
    }
    
    int T, P, Q;
    cin>>T;
    int max = *max_element(arr.begin(), arr.end());
    vector<int> count(max+1, 0);       // Map the value in array to its indexes
    vector<int> ans(max+1, 0);          // Stores the number of multiples of possible values.
    create_sieve(arr, ans, count, max);
    for(int i=0; i<T; i++){
        cin>>P>>Q;
        cout<<get_output(ans, P, Q, max)<<endl;
    }
    return 0;
}