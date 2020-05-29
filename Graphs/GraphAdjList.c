#include<stdio.h>
#include<stdlib.h>

struct AdjListNode{
    int dest;
    struct AdjListNode*  next;
};

struct AdjList{
    struct AdjListNode* head;
};

struct Graph{
    int size;
    struct AdjList* arr;
};

struct AdjListNode* addAdjListNode(int dest){
    struct AdjListNode* newNode=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest=dest;
    newNode->next=NULL;
    return newNode;
}

struct Graph* NewGraph(int v){
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->size=v;
    graph->arr=(struct AdjList*)malloc(sizeof(struct AdjList));
    for(int i=0;i<v;++i)
        graph->arr[i].head=NULL;

    return graph;
}


void addEdge(struct Graph* graph, int src, int dest){
    struct AdjListNode* newNode= addAdjListNode(dest);
    newNode->next=graph->arr[src].head;
    graph->arr[src].head=newNode;

    newNode=addAdjListNode(src);
    newNode->next=graph->arr[dest].head;
    graph->arr[dest].head=newNode;
}

void printGraph(struct Graph* graph){
    for(int i=0;i<graph->size;i++){
        struct AdjListNode* Crawler=graph->arr[i].head;
        printf("AdjList of %d Vertxe->Head->",i);
        while(Crawler){
            printf("%d->",Crawler->dest);
            Crawler=Crawler->next;
        }
    printf("\n");
    }
}

int main(){
    int v;
    printf("Enter Number Of Vertices: ");
    scanf("%d",&v);
    struct Graph* graph=NewGraph(v);
    int* src=(int*)malloc(sizeof(int)*v);
    int* dest=(int*)malloc(sizeof(int)*v);
    for(int i=0;i<v;i++){
        printf("enter src: ");
        scanf("%d",&src[i]);
        printf("Enter dest: ");
        scanf("%d",&dest[i]);
    }

    for(int i=0;i<v;i++)
        addEdge(graph,src[i],dest[i]);

        printGraph(graph);
}