#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector <pair<int,int>> adj[],int u, int v ,int wt){
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}

void printGraph(vector <pair<int,int>> adj[],int size){
    int f,s;
    for(int v=0;v<size;v++){
        cout<<"Node "<<v<<"->";
        for(auto it=adj[v].begin();it!=adj[v].end();it++){
            f=it->first;
            s=it->second;
            cout<<"( "<<f<<","<<s<<" )"<<"->";
        }
        cout<<endl;
    }
}

int main() 
{ 
    int V = 5; 
    vector<pair<int, int> > *adj=new vector<pair<int,int>>[V]; 
    addEdge(adj, 0, 1, 10); 
    addEdge(adj, 0, 4, 20); 
    addEdge(adj, 1, 2, 30); 
    addEdge(adj, 1, 3, 40); 
    addEdge(adj, 1, 4, 50); 
    addEdge(adj, 2, 3, 60); 
    addEdge(adj, 3, 4, 70); 
    printGraph(adj, V); 
    return 0; 
} 