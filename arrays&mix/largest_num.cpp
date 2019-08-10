#include<iostream>
#include<vector>
using namespace std;

string largestNumber(const vector<int> &A) {
    vector<int> B;
    for(int i=0; i<A.size(); i++) B.push_back(A[i]);
    string ans = "";
    int len = A.size();
    int one;
    int two;
    for(int i=0; i<len; i++){
        int big = B[0];
        int index = 0;
        for(int j=1; j<len-i; j++){
            cout<<"Adding.. "<<big<<"   "<<B[j]<<endl;
            one = stoi(to_string(big) + to_string(B[j]));
            two = stoi(to_string(B[j]) + to_string(big));
            cout<<"ONE: "<<one<<"     "<<"TWO: "<<two<<endl;
            if(two>one){
                big = B[j];
                index = j;
            }
            else if(one == two){
                if(B[j]>big){
                    big = B[j];
                    index = j;
                }
            }
            cout<<"Current BIG: "<<big<<endl;
        }
        cout << "BIG: " << to_string(big) << endl;
        if(ans == "0" && big == 0){
            ans = ans;
        }
        else{
            ans = ans + to_string(big);
        }
        cout<<"Removing from array: "<<B[index]<<endl;
        B.erase(B.begin()+index);
    }
    return ans;
}

int main(){
    const vector<int> A = {0, 0, 0, 0, 0};
    string ans = largestNumber(A);
    cout << "ANSWER: " << ans << endl;
}