//dfs

#include <stdio.h>
#include <stdlib.h>

#define MAX 20  // Maximum number of vertices in the graph

//graph 
struct Graph {
    int numVertices;
    int adjMat[MAX][MAX];
};

//create graph
struct Graph* createGraph(int vertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->adjMat[i][j] = 0;
        }
    }

    return graph; 
}

//add edge
void addEdge(struct Graph* graph,int src,int dest){
    graph->adjMat[src][dest] = 1;
    graph->adjMat[dest][src] = 1;
}
//dfs
void DFS(struct Graph* graph,int vertex,int visited[]){
    visited[vertex] = 1;
    printf("Current Vertex %d", vertex);

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->adjMat[vertex][i]==1 && !visited[i])
        {
            DFS(graph,i,visited);
        }
        
    }
    
}
//perform dfs
void performDFS(struct Graph* graph,int vertex){
    int visited[MAX] = {0};
    printf("Starting Operation from %d" , vertex);

    DFS(graph,vertex,visited);
}
//main

int main()
{
    int vertices, edges, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    performDFS(graph, startVertex);

    // Free the allocated memory
    free(graph);

    return 0;
    return 0;
}
