#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct graph
{
  int vertices;
  bool adj[MAX][MAX];
} Graph;

Graph *createGraph(int vertices)
{
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->vertices = vertices;
  int i, j;
  for (i = 0; i < vertices; i++)
  {
    for (j = 0; j < vertices; j++)
    {
      g->adj[i][j] = false;
    }
  }
  return g;
}

void addEdge(Graph *g, char src, char dest)
{
  g->adj[src - 'a'][dest - 'a'] = true;
}

void BFS(Graph *g, char start)
{
  bool visited[MAX];
  char queue[MAX];
  int i, front = 0, rear = 0;
  for (i = 0; i < g->vertices; i++)
  {
    visited[i] = false;
  }
  visited[start - 'a'] = true;
  queue[rear++] = start;
  while (front < rear)
  {
    start = queue[front++];
    printf("%c ", start);
    for (i = 0; i < g->vertices; i++)
    {
      if (g->adj[start - 'a'][i] == true && visited[i] == false)
      {
        visited[i] = true;
        queue[rear++] = i + 'a';
      }
    }
  }
}

int main()
{
  int vertices, edges, i;
  char src, dest, start;
  
  printf("--SOCIAL NETWORK--");
  printf("\nEnter the number of users:\n");
  scanf("%d", &vertices);

  Graph *g = createGraph(vertices);

  printf("Enter the number of connections:\n");
  scanf("%d", &edges);

  printf("We want to represent the social network in the form of a graph.");
  printf("\nUsers are vertices and Connections are edges.");
  printf("\nEnter the value of edge list form (source, destination) (a to z):\n");

  for (i = 0; i < edges; i++)
  {
    scanf(" %c %c", &src, &dest);
    addEdge(g, src, dest);
  }

  printf("Enter the starting vertex (a to z):\n");
  scanf(" %c", &start);

  printf("BFS Traversal:\n");
  BFS(g, start);
  
  printf("\n");
  return 0;
}
