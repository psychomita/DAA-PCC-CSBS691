#include <stdio.h>
#include <limits.h>

void bellmanFord(int graph[][3], int vertices, int edges, int distance[], int source)
{
  distance[source] = 0; 
  int count;

  for (count = 1; count < vertices; count++) 
  {
    int i, u, v, wt;
    for (i = 0; i < edges; i++)
    {
      u = graph[i][0];  
      v = graph[i][1];  
      wt = graph[i][2]; 
      if (distance[u] != INT_MAX && (distance[u] + wt) < distance[v]) 
        distance[v] = distance[u] + wt;
    }
  }

  for (int i = 0; i < edges; i++)
  {
    int u = graph[i][0];
    int v = graph[i][1];
    int wt = graph[i][2];

    if (distance[u] != INT_MAX && distance[u] + wt < distance[v])
    {
      printf("Graph contains negative weight cycle.\n"); 
    }
  }
}

void printDistance(int distance[], int source, int vertices)
{
  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < vertices; i++)
    printf("%d\t\t%d\n", i, distance[i]);
}

int main()
{
  int vertices, edges;
  printf("Welcome to LinkedIn! The social network is implemented in the form of a graph. \nUsers are represented as vertices and Connections between them are represented as edges. \nAll connections help you equally.");
  printf("\nEnter the no. of Vertices:\n");
  scanf("%d", &vertices); 
  int distance[vertices];
  int source, i;
  printf("Enter no. of Edges:\n");
  scanf("%d", &edges); 
  int graph[edges][3];
  printf("Enter the Adjacency List (Source, Destination and Cost):\n");
  for (i = 0; i < edges; i++) 
    scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
  for (i = 0; i < vertices; i++)
    distance[i] = INT_MAX; 
  printf("Enter the Source vertex:\n");
  scanf("%d", &source);   
  printf("The shortest distances from source to other vertices are:\n");                               
  bellmanFord(graph, vertices, edges, distance, source); 
  printDistance(distance, source, vertices);             
  return 0;
}
