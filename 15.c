//bfs

#include<stdio.h>
#include<stdlib.h>

#define N 20

//graph
struct Graph
{
    int numVertices;
    int adjMat[N][N];
};

//createGraph
struct Graph* createGraph(int vertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++){
            graph->adjMat[i][j]= 0;
        }
    }

    return graph;
}
//addEdge
void addEdge(struct Graph* graph,int src,int dest){
    graph->adjMat[src][dest] = 1;
    graph->adjMat[dest][src] = 1;
}

//bfs
void BFS(struct Graph* graph, int startVertex){
    int visited[N] ={0};
    int queue[N];
    int rear = -1;
    int front = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("%d is starting vertex ", startVertex);

    while(front != rear){
        front++;
        int currentVertex = queue[front] ;

        printf("%d", currentVertex);

        for (int i = 0; i < graph->numVertices; i++)
        {
            if (graph->adjMat[currentVertex][i] == 1 && !visited[i])
            {
                visited[currentVertex] = 1;
                queue[++rear] = i;
            }    
        } 
    }
}

void main(){
    int vertices,edges,src,dest;

    printf("Enter Number Of Vertices ");
    scanf("%d",&vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter Number Of Edges ");
    scanf("%d",&edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (src -> destination)");
        scanf("%d %d",&src,&dest);
        addEdge(graph,src,dest);
    }

    int startVertex;
    printf("Enter Start Vertex");
    scanf("%d",&startVertex);
    BFS(graph,startVertex);

    free(graph);
    
}