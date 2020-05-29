#include <iostream>
#include<vector>
using namespace std; 

void addEdge(vector<int> adj[],int u,int v){
adj[u].push_back(v);
adj[v].push_back(u);
}

void DFSutil(int u, vector<int> adj[], vector<bool>&visited){
 visited[u] = true; 
    cout << u << " "; 
    for (int i=0; i<adj[u].size(); i++) 
        if (visited[adj[u][i]] == false) 
            DFSutil(adj[u][i], adj, visited);    
}

void DFS(vector<int> adj[],int v){
    vector<bool> visited(v, false); 
    for (int u=0; u<v; u++) 
        if (visited[u] == false) 
            DFSutil(u, adj, visited); 
}

int main(){
    int y;
    cout<<"enter number of vertices: "<<endl;
    cin>>y;
    vector<int> *adj= new vector<int>[y];
    vector<int> src;
    vector<int> dest;
    for(;;){
        int n,m;
        cout<<"Enter src: ";
        cin>>n;
        if(n<0) break;
        src.push_back(n);
        cout<<"enter dest: ";
        cin>>m;
        if(m<0) break;
        dest.push_back(m);   
    }
    for(int i=0;i<src.size();++i)
    addEdge(adj,src[i],dest[i]);
    
    DFS(adj,y); 

}