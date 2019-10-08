#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int> &arr, int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k =0;
    int temp[high-low+1];
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid){
        temp[k] = arr[i];
        i++; k++;
    }

    while(j<=high){
        temp[k] = arr[j];
        j++; k++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}
void merge_sort(vector<int> &arr, int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void printArr(vector<int> &arr, int num){
    for(int i=0; i<num; i++){
        cout<<arr[i]<<"  ";
    }
}
int main(){
    cout<<"Enter the size of array: ";
    int num;
    vector<int> arr;
    cin >> num;
    for(int i=0; i<num; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    } 
    merge_sort(arr, 0, num-1);
    printArr(arr, num);
    return 0;
}