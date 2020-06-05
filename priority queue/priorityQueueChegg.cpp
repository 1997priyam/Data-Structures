#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

class PriorityQueue {
    public:
        virtual void insert(int item, int priority) = 0;
        virtual pair<int, int> getHighestPriority() = 0;
        virtual void deleteHighestPriority() = 0;
};

class PriorityQueueArrayBased : public PriorityQueue {
    private:
        vector<pair<int, int>> arr;
        int size;

        int parent(int node){
        return (node/2);
        }   

        int leftChild(int node){
            return (2*node);
        }

        int rightChild(int node){
            return (2*node)+1;
        }

        void heapify(int num){
            int maxIndex = num;
            int l = leftChild(num);
            int r = rightChild(num);
            if(l<=size && arr[l-1]>arr[maxIndex-1]){
                maxIndex = l;
            }
            if(r<=size && arr[r-1]>arr[maxIndex-1]){
                maxIndex = r;
            }
            if(maxIndex!=num){
                swap(arr[maxIndex-1], arr[num-1]);
                heapify(maxIndex);
            }
        }

    public:
        PriorityQueueArrayBased(int size) : size(size) {
        };

        void insert(int item, int priority) override {
            pair<int, int> data = make_pair(item, priority);
            arr.push_back(data);
            heapify(data.second);
        };


        pair<int, int> getHighestPriority() override {
            return arr[0];
        };

        void deleteHighestPriority() {
            arr[0] = arr.back();
            arr.pop_back();
            heapify(0);
        };
};

int main() {
    PriorityQueueArrayBased pq = PriorityQueueArrayBased(10);
    pq.insert(100, 2);
    pq.insert(1200, 1);
    cout << pq.getHighestPriority().first;
    return 0;
}