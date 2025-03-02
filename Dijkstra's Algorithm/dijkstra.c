#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

void dijkstra(int vertices, int graph[vertices][vertices], bool final[], int distance[], int predecessor[], int source)
{
  distance[source - 1] = 0; 
  int count;
  for (count = 0; count < vertices - 1; count++) // to get vertex wih minimum weight
  {
    int min = INT_MAX, index = -1, i;
    for (i = 0; i < vertices; i++)
    {
      if (!final[i] && distance[i] < min)
      {
        index = i;         
        min = distance[i]; 
      }
    }
    final[index] = true; // add to shortest path

    for (i = 0; i < vertices; i++)
    {
      if (graph[index][i] != 0 && !final[i] && (distance[index] + graph[index][i] < distance[i]))
      {
        distance[i] = distance[index] + graph[index][i]; 
        predecessor[i] = index;                          
      }
    }
  }
}

void printPath(int predecessor[], int v, int source)
{
  if (v == source - 1)
  {
    printf("%d->", source);
    return;
  }
  printPath(predecessor, predecessor[v], source);
  printf("%d->", v + 1);
}

void printDistance(int vertices, int distance[], int predecessor[], int source)
{
  int i;
  printf("Vertex\tDistance\tPath\n");
  for (i = 0; i < vertices; i++)
  {
    if (i == source - 1)
      continue;
    printf("%d\t%d\t\t", i + 1, distance[i]);
    printPath(predecessor, i, source);
    printf("\n");
  }
}

int main()
{
  int vertices;
  printf("Welcome to LinkedIn! The social network is implemented in the form of a graph. \nUsers are represented as vertices and Connections between them are represented as edges. \nStronger connections are assumed to have minimum edge weights.");
  printf("\n\nEnter the no. of vertices (numbered from 1 to n) : ");
  scanf("%d", &vertices);
  int graph[vertices][vertices];
  printf("Enter your social connection graph in the form of a Adjacency Matrix : \n");
  int row, col, i, source;
  for (row = 0; row < vertices; row++)
  {
    for (col = 0; col < vertices; col++)
    {
      scanf("%d", &graph[row][col]);
      if(graph[row][col] < 0)
      {
      	printf("\nNegative edges not allowed. Run again!\n");
      	exit(0);
      }
    }
  }

  bool final[vertices];      // shortest path
  int distance[vertices];    // shortest distance from source to each vertex
  int predecessor[vertices]; // predecessor of each vertex in the path

  for (i = 0; i < vertices; i++)
  {
    final[i] = false;
    distance[i] = INT_MAX; 
    predecessor[i] = -1;   
  }

  printf("Enter the Source vertex (Self User) : ");
  scanf("%d", &source);                                            
  dijkstra(vertices, graph, final, distance, predecessor, source); 
  printf("The shortest paths from source to other vertices are:\n");
  printDistance(vertices, distance, predecessor, source);          
  return 0;
}
