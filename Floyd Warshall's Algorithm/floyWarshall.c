#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INF 99999

void printPath(int src, int dest, int n, int pred[][n])
{
	if (src==dest) 
	{
		printf("%d",src); 
		return;
		
	}
	if(pred[src][dest]==-1) 
	{
		printf("No path from %d to %d",src,dest);
		return;
	}
	printPath(src,pred[src][dest],n,pred); 
	printf("-> %d",dest); 
	
}
void printDistance(int n,int cost[][n]) 
{
	printf("\nThe distance matrix is:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if (cost[i][j]==INF) 
				printf("INF");
			else
				printf("%d\t",cost[i][j]); 
		}
		printf("\n");
	}
}
void floyd(int n, int cost[][n]) 
{	
	int pred[n][n];
	
	for(int i=0;i<n;i++) 
	{
		for(int j=0;j<n;j++)
		{
			pred[i][j]= (i==j)?-1:i;
		}
	}
	for(int k=0;k<n;k++) 
	{
		for(int i=0;i<n;i++) 
		{
			for(int j=0;j<n;j++) 
			{				
				if((cost[i][k]+cost[k][j])<cost[i][j])
				{					
					cost[i][j]=cost[i][k]+cost[k][j];
					pred[i][j]=pred[k][j];
				}
			}
		}
	}
	printDistance(n,cost); 
	printf("\nThe shortest path between:\nSource\tDestination\tPath\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j) 
			{
			  	printf("%d\t%d\t\t",i,j);
				printPath(i,j,n,pred);
				printf("\n");
			}
		}
	}
}

int main()
{
	int vertices;	
	printf("Welcome to LinkedIn! The social network is implemented in the form of a graph. \nProfessionals are represented as vertices and Direct Relationships between them are represented as edges. \nEach connection has a strength score that indicates the quality of the relationship. \nStronger connections have lower scores.");
	printf("\nEnter the number of vertices:\n");
	scanf("%d",&vertices);
	int cost[vertices][vertices];
	printf("Enter the adjacency matrix:\n");
	for(int i=0;i<vertices;i++) 
	{
		for(int j=0;j<vertices;j++)			
			scanf("%d",&cost[i][j]);
	}
	printf("The strongest and shortest path between every pair of professionals in the network are:\n");
	floyd(vertices,cost);
	return 0;
}
