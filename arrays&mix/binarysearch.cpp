#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int binarySearch(int *Arr, int n, int target) {

	int start = 0, end = n-1;

	while(start <= end) {
		int mid = (start + end) / 2;
		if(Arr[mid] == target) {
			return mid+1; 
		}
		else if(Arr[mid] < target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}
int main(){
    cout<<"Enter the size of array: ";
    int n;
    cin>>n;
    cout<<"Enter the elements in sorted form: ";
    int* A;
    for(int i=0; i<n; i++){
        cin>>*(A+i);
    }
    cout<<"Entered array is: ";
    for(int i=0; i<n; i++){
        cout<<*(A+i)<<" ";
    }
    cout<<"Enter the number to be searched: ";
    int target;
    cin>>target;
    int pos;
    pos = binarySearch(A, n, target);
    cout<<"Position of target number is: "<<pos<<endl;
}