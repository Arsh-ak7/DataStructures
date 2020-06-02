#include<iostream>
#include<vector>
using namespace std;


bool isCyclicUtil(vector<int> adj[],vector<bool> visited,int curr){
if(visited[curr]==true) //The boundary case where we need to break;
return true;
visited[curr]=true;
bool flag= false;
for(int i=0;i<adj[curr].size();i++){
    flag=isCyclicUtil(adj,visited,i);
    if(flag==true)
    return true;
}
return false;
}


bool isCyclic(vector<int>adj[],int v){
    vector<bool> visited(v,false);
    bool flag=false;
    for(int i=0;i<v;i++){
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++){
            flag=isCyclicUtil(adj,visited,adj[i][j]);
            if(flag==true)
            return true;
        }
        visited[i]=false;
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
        adj[src-1].push_back(dest-1);
    }
   cout<< isCyclic(adj,v);
}