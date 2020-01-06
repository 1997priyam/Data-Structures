/*
Monk has recently created a matrimonial site. X men and Y women registered there. 
As Monk has access to everyone's Facebook profile, he can see whether a person is a friend of another person or not. 
He doesn't want any two people who are in a single group to get married together. 
So, first we have  relationships among men. Then, we have  relationships among women. 
Finally we have  relationships among men and women. Read the input format for more clarity. 
Now, Monk wants to calculate the total number of unique marriages he can set between men and women provided 
the conditions are followed.

Note - Two person are said to be in a group if they are friends directly or connected through a chain of mutual friends.

Input:
The first line consists of X and Y.
Next line consists of variable .
The next  lines will have two integers of the form A B where A and B are both men and are friends on facebook and.
Next line consists of variable .
The next  lines will have two integers of the form A B where A and B are both women and are friends on facebook and .
Next line consists of variable .
The next  lines will have two integers of the form A B where A is a man and B is a woman and they both are friends on facebook.

Output:
Print in a single line the answer.
//*/


#include <iostream>
#include <vector>

using namespace std;

void explore(int vertex, vector<vector<int>> &graph, vector<int> &visited, vector<int> &group){
    visited[vertex] = 1;            // Visiting the node
    group.push_back(vertex);        // Pushing in the group vector
    for(int neighbour: graph[vertex]){  // Iterating over its neighbours
        if(visited[neighbour] == 0){
            explore(neighbour, graph, visited, group);  // Recursive call to visit the neighbours
        }
    }
}

vector<vector<int>> find_group(vector<vector<int>> &graph){
    vector<vector<int>> groups;             // It stores the people in each group in a form of 2D matrix
    vector<int> visited(graph.size(), 0);   // It keeps track of the visited nodes of graph.
    for(int i=0; i<graph.size(); i++){      // Depth First Search on graph
        if(visited[i] == 0){
            vector<int> group;              // It stores the people of 1 group 
            explore(i, graph, visited, group);  // Helper for recursion
            groups.push_back(group);        // Pushing the people of 1 group in the groups vector
        }
        
    }
    return groups;
}

bool isMan(int person, int men){
    if(person<men){                 // If the index of node is less than the number of man its a man else woman
        return true;
    }
    return false;
}

int get_output(vector<vector<int>> &group, int men){
    int result = 0;
    vector<int> man, woman;             // Vectors to store the number of man and woman in each group.
    for(int i=0; i<group.size(); i++){  // Index represents the group number
        int male=0;
        int female=0;
        for(int j=0; j<group[i].size(); j++){      // Converting the groups vector to man and woman vectors 
            if(isMan(group[i][j], men)){           // Inserting the number of man and woman in each group in the respective vectors
                male++;
            }
            else{
                female++;
            }
        }
        man.push_back(male);
        woman.push_back(female);    
    }
    
    for(int i=0; i<man.size(); i++){
        for(int j=0; j<woman.size(); j++){
            if(i!=j){                                  // If iterating over the same group- SKIP
                result = result + (man[i]*woman[j]);   // multiply the number of man with number of woman in other group
            }                                          // and add to the results
        }
    }
    return result;              // return the final result

}

int main(){
    int X, Y;       // A single graph is constructed which will store both man and woman. Firstly the man will be stored
    cin>>X>>Y;      // in the adjacency list and then after all man, woman will be stored.
    vector<vector<int>> graph(X+Y, vector<int>()); // Creating a graph of size of sum of both man and woman
    int q1, q2, q3;
    cin>>q1;
    int a,b;
    for(int i=0; i<q1; i++){
        cin>>a>>b;
        graph[a-1].push_back(b-1);      // Pushing it into the graph 
    }
    cin>>q2;
    for(int i=0; i<q2; i++){
        cin>>a>>b;
        graph[a+X-1].push_back(b+X-1);     // Pushing the woman after man in the graph
    }
    cin>>q3;
    for(int i=0; i<q3; i++){
        cin>>a>>b;
        graph[a-1].push_back(b+X-1);        // Pushing the man- woman relations in graph.
    }
    vector<vector<int>> groups = find_group(graph); // It will create groups of man and woman 
    cout<<get_output(groups, X);
    return 0;
}