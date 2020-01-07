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

class element{              // Class which represents an element of the Disjoint set
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
    if(set[person].parent != person){                       // If the parent is not equal to root 
        set[person].parent = find(set, set[person].parent);  // find the parent of that node until the root is found and hence it will be the ID.
    }
    return set[person].parent;          // Return the updated parent
}


bool merge_group(vector<element> &set, int source, int dest){
    int id1 = find(set, source);    // Finding ID of both source and destination.
    int id2 = find(set, dest);
    if(id1==id2){               // If the IDs are equal no need to merge as they are already in same group.
        return false;          //  Return false since the group is not merged.
    }
    else{
        int rank1 = set[id1].rank;      // Finding the ranks of the parents of source and destination 
        int rank2 = set[id2].rank;
        
        if(rank1>rank2){            // Merging under the one having greater rank
            set[id2].parent = id1;      // Changing the parent 
            set[id1].size += set[id2].size; // Increasing the size of the new group by adding present size of groups
            set[id2].size = 0;          // Resetting the size of group to 0 / optional
        }
        else{
            set[id1].parent = id2;      // Vice versa of the above process
            set[id2].size += set[id1].size;
            set[id1].size = 0;
            if(rank1==rank2){       // If the ranks are equal merge anhy group under any and increase the rank 
                set[id2].rank++;
            }
        }
        return true;        // Returning true since the actual merge happened here.
    }
}

int get_difference(vector<element> &set){
    int smallest = INT32_MAX;
    int largest = INT32_MIN;
    for(int i=0; i<set.size(); i++){       // Finding the smallest and the largest group sizes
        int id = find(set, i);
        int size = set[id].size;
        if(size>largest) largest = size;
        if(size<smallest) smallest = size;
    }
    return largest - smallest;      // Returning the difference as requested.
}

int main(){
    int N, Q;
    cin>>N>>Q;
    vector<element> set;    
    for(int i=0; i<N; i++){
        set.push_back(element(1,i,0));  // Pushing each person as a group in itself with size-1 , parent- itself, and rank-0
    }
    int source, destination;
    int total_groups = N;               // Variable to keep track if total groups is 1. Then return 0.
    bool flag = true;                   // Flag to check if there is 1 group then print 0. and don't calculate the distance.
    for(int i=0; i<Q; i++){
        cin>>source>>destination;
        if(merge_group(set, source-1, destination-1)){  // Taking the source and destination and merging them in the group
            total_groups--;                         // Subtracting 1 group if merge is successful.
            if(total_groups==1){            // If remaining group is 1 then print 0 and exit.
                cout<<0;
                flag = false;
                break;
            }
        }
    }
    if(flag){                           // If the total groups are greater than 1 then calculate the difference b/w largest and smallest as requested.
        cout<<get_difference(set);
    }
    return 0;
}