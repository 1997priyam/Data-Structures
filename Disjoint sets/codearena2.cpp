/*
"Money money MONEY, I want money" thought Alex. "Now how do I get money? Well... I'll open up a camp!"

Well, unfortunately things didn't go so well for Alex's campers, and now there are N campers wandering around the city aimlessly.
You have to handle Q queries; which consist of two groups finding each other and becoming one larger group. 
After each query, output the difference between the group of largest size and group of smallest size. 
If there is only one group, output 0. At first, everyone is in their own group.

Also note, if the two campers in the query are already in the same group, print the current answer, and skip merging the groups together.

Input:

The first line consists of two space separated integers, N and Q

The next Q line consists of two integers, A and B, meaning that the groups involving camper A and camper B find each other.

Output:

Output Q lines, the answer after each query.

Constraints:

1 <= N <= 105

1 <= Q <= 105

SAMPLE INPUT 
2 1
1 2
SAMPLE OUTPUT 
0
Explanation
Here, the two campers find each other, so the answer is 0.
//*/


#include <iostream>
#include <vector>

using namespace std;

class element{
    public:
        int rank;
        int size;
        int parent;
        element(int size=0, int parent=-1, int rank=0){
            this->size = size;
            this->parent = parent;
            this->rank = rank;
        }
};

int find(vector<element> &set, int person){
    if(set[person].parent != person){
        set[person].parent = find(set, set[person].parent);
    }
    return set[person].parent;
}


bool merge_group(vector<element> &set, int source, int dest){
    int id1 = find(set, source);
    int id2 = find(set, dest);
    if(id1==id2){
        return false;
    }
    else{
        int rank1 = set[id1].rank;
        int rank2 = set[id2].rank;
        
        if(rank1>rank2){
            set[id2].parent = id1;
            set[id1].size += set[id2].size;
            set[id2].size = 0;
        }
        else{
            set[id1].parent = id2;
            set[id2].size += set[id1].size;
            set[id1].size = 0;
            if(rank1==rank2){
                set[id2].rank++;
            }
        }
        return true;
    }
}

int get_difference(vector<element> &set){
    int smallest = INT32_MAX;
    int largest = INT32_MIN;
    for(int i=0; i<set.size(); i++){
        int id = find(set, i);
        int size = set[id].size;
        if(size>largest) largest = size;
        if(size<smallest) smallest = size;
    }
    return largest - smallest;
}

int main(){
    int N, Q;
    cin>>N>>Q;
    vector<element> set;
    for(int i=0; i<N; i++){
        set.push_back(element(1,i,0));
    }
    int source, destination;
    int total_groups = N;
    bool flag = true;
    for(int i=0; i<Q; i++){
        cin>>source>>destination;
        if(merge_group(set, source-1, destination-1)){
            total_groups--;
            if(total_groups==1){
                cout<<0;
                flag = false;
                break;
            }
        }
    }
    if(flag){
        cout<<get_difference(set);
    }
    return 0;
}