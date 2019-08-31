#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
vector <int> adj[MAX];      // adjacency matrix, where adj[i] is a list, which denotes there are edges from i to each vertex in the list adj[i]
bool visited[MAX];          // boolean array, hacing value true / false, which denotes if a vertex 'i' has been visited or not.


void init(){                // initialization function
    int i;
    for(i = 0; i < MAX; i++){
        visited[i] = false; // marking all vertex as unvisited
        adj[i].clear();     // clearing all edges
    }
}

void BFS(int start){
    
    init();
    queue <int> q;
    q.push(start);
    
    int iterator, current_node, next_node;
    cout<<"BFS Traversal is:\n";
    while(!q.empty()){
        current_node = q.front();
        q.pop();
        
        if(visited[current_node] == true){
            continue;
        }
        
        cout<<current_node<<" ";
        visited[current_node] = true;
        
        for(iterator = 0; iterator < adj[current_node].size(); iterator++){
            next_node = adj[current_node][iterator];
            
            if(visited[next_node] == false) {
                q.push(next_node);
            }
        }
    }
    
}

int main(){
    int vertices, edges;
    cout<<"Enter Number of Vertices:\n";
    cin>>vertices;
    cout<<"Enter number of edges:\n";
    cin>>edges;
    
    int i;
    int source, destination;
    cout<<"Enter Edges as (source) <space> (destination):\n";
    for(i=0; i<edges; i++){
        cin>>source>>destination;
        if(source > vertices || destination > vertices){
            cout<<"Invalid Edge";
            i--;
            continue;
        }
        adj[source].push_back(destination);
        adj[destination].push_back(source);
    }
    
    int start;
    cout<<"Enter Starting Vertex:";
    cin>>start;
    
    BFS(start);
}