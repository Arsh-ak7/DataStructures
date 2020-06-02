#include<iostream>
#include<vector>
using namespace std;

bool isCyclicUtil(vector<int> adj[],vector<int> visited,int curr){
if(visited[curr]==2) //The Boundary case where we need to break;
    return true;
visited[curr]=1;
bool flag= false;
for(int i=0;i<adj[curr].size();i++){
    if(visited[adj[curr][i]==1]){
        visited[adj[curr][i]]=2;
    }
    else{
    flag=isCyclicUtil(adj,visited,i);
    if(flag==true)
    return true;
    }
}
return false;
}


bool isCyclic(vector<int>adj[],int v){
    vector<int> visited(v,0);
    bool flag=false;
    for(int i=0;i<v;i++){
        visited[i]=1;
        for(int j=0;j<adj[i].size();j++){
            flag=isCyclicUtil(adj,visited,adj[i][j]);
            if(flag==true)
            return true;
        }
        visited[i]=0;
    }
    return false;
}

int main(){
    int e,v;
    cout<<"Enter NUmber of Vertices and Edges ";
    cin>>v>>e;

    vector<int>*adj=new vector<int>[v];
    for(int i=0;i<e;i++){
        cout<<"Enter src and dest ";
        int src,dest;
        cin>>src>>dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
   cout<< isCyclic(adj,v);
}