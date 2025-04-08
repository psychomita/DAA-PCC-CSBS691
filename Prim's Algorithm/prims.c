#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
  int V;     
  int **adj; 
} Graph;

void printMST(int parent[], int key[], int V)
{
  int i, j, sum = 0;
  printf("\nMinimum Spanning Tree\n");
  printf("Edge \tWeight\n");
  for (i = 1; i < V; i++)
  {
    printf("%c - %c \t%d\n", parent[i] + 'a', i + 'a', key[i]);
    sum += key[i];
  }
  
  printf("\nThe total introduction cost is %d.\n", sum);
  
}

int findMinKey(int key[], bool mstSet[], int V)  
{
  int min = -1, v;
  for (v = 0; v < V; v++)
  {
    if (!mstSet[v] && (min == -1 || key[v] < key[min]))
      min = v;
  }
  return min; 
}

void primMST(Graph *graph)
{
  int parent[graph->V]; 
  int key[graph->V]; 
  bool mstSet[graph->V]; 
  int i, count;

  for (i = 0; i < graph->V; i++)
  {
    key[i] = 10000; 
    mstSet[i] = false; 
  }

  key[0] = 0; 
  parent[0] = -1; 

  for (count = 0; count < graph->V - 1; count++) 
  {
    int u = findMinKey(key, mstSet, graph->V); 
    mstSet[u] = true; 
    int v;

    for (v = 0; v < graph->V; v++) 
    {
      if (graph->adj[u][v] && !mstSet[v] && graph->adj[u][v] < key[v])
      {
        parent[v] = u; 
        key[v] = graph->adj[u][v]; 
      }
    }
  }

  printMST(parent, key, graph->V); 
}

int main()
{
  Graph graph;
  int i, j;
  printf("Welcome to LinkedIn! The social network is implemented in the form of a graph. \nProfessionals are represented as vertices and Direct Relationships between them are represented as edges. \nEach connection has a strength score that indicates the quality of the relationship. \n\nThe goal is to connect all professionals in the network while minimizing the overall introduction effort.\n");
  printf("Enter the number of vertices:\n");
  scanf("%d", &graph.V);

  printf("Enter the number of edges:\n");
  int edges;
  scanf("%d", &edges);

  graph.adj = (int **)malloc(graph.V * sizeof(int *)); 
  for (i = 0; i < graph.V; i++)
  {
    graph.adj[i] = (int *)malloc(graph.V * sizeof(int));  
    for (j = 0; j < graph.V; j++)
      graph.adj[i][j] = 0; 
  }

  int src, dest;
  int weight;

  for (i = 0; i < edges; i++)
  {
    char src_char, dest_char;
    printf("Enter value of edge %d (src, dest, weight): ", i+1);
    scanf(" %c %c %d", &src_char, &dest_char, &weight);
    src = src_char - 'a'; 
    dest = dest_char - 'a';
    graph.adj[src][dest] = weight; 
    graph.adj[dest][src] = weight; 
  }
  
  printf("\nThe subset of connections connecting all professionals with minimum connection strength cost is represented in the form of a MST.\n");
  primMST(&graph);
  
  free(graph.adj);
  return 0;
}
