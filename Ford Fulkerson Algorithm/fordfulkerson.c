#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100 // Maximum number of vertices

// Function to print the residual graph
void printResidualGraph(int V, int rGraph[MAX][MAX]) {
    printf("\nResidual Graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", rGraph[i][j]);
        }
        printf("\n");
    }
}

// Function to find an augmenting path using DFS
bool dfs(int V, int rGraph[MAX][MAX], int s, int t, int parent[]) {
    bool visited[MAX];
    memset(visited, 0, sizeof(visited));

    int stack[MAX], top = -1;
    stack[++top] = s;
    visited[s] = true;
    parent[s] = -1;

    while (top >= 0) {
        int u = stack[top--];

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) { // If there is residual capacity
                parent[v] = u;
                stack[++top] = v;
                visited[v] = true;
                if (v == t) return true; // Found a path to the sink
            }
        }
    }
    return false;
}

// Function to implement Ford-Fulkerson algorithm
int fordFulkerson(int V, int graph[MAX][MAX], int s, int t, int rGraph[MAX][MAX]) {
    memcpy(rGraph, graph, sizeof(int) * MAX * MAX); // Copy original graph

    int parent[MAX]; // Stores path from source to sink
    int max_flow = 0; // Initial flow is 0

    while (dfs(V, rGraph, s, t, parent)) {
        int path_flow = INT_MAX;

        // Find bottleneck capacity in the found path
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = (path_flow < rGraph[u][v]) ? path_flow : rGraph[u][v];
        }

        // Update residual capacities
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

// Driver code
int main() {
    int V, E, graph[MAX][MAX], rGraph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Initialize adjacency matrix with 0
    memset(graph, 0, sizeof(graph));

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges in format (u v capacity):\n");
    for (int i = 0; i < E; i++) {
        int u, v, capacity;
        scanf("%d %d %d", &u, &v, &capacity);
        graph[u][v] = capacity; // Directed edge
    }

    int s, t;
    printf("Enter source node: ");
    scanf("%d", &s);
    printf("Enter sink node: ");
    scanf("%d", &t);

    int maxFlow = fordFulkerson(V, graph, s, t, rGraph);
    
    // Print final residual graph
    printResidualGraph(V, rGraph);

    printf("\nThe maximum possible flow is %d\n", maxFlow);

    return 0;
}

