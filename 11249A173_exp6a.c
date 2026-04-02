#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6
int i,j;
int min_dist(int dist[], bool visited[]) 
{
    int min = INT_MAX, index = -1;

    for (i = 0; i < V; i++) 
	{
        if (!visited[i] && dist[i] < min) 
		{
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[V][V], int src) 
{
    int dist[V];
    bool visited[V];
    int i,count;

    for (i = 0; i < V; i++) 
	{
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (count= 0; count < V - 1; count++) 
	{
        int m= min_dist(dist, visited);
        visited[m] = true;

        for (i= 0; i < V; i++) 
		{
            if (!visited[i] && graph[m][i] != 0 &&
                dist[m] != INT_MAX &&
                dist[m] + graph[m][i] < dist[i]) 
				{

                dist[i] = dist[m] + graph[m][i];
            }
        }
    }

    printf("Vertex\tDistance\n");
    for (i = 0; i < V; i++) 
	{
        printf("%c\t%d\n", 'A'+i , dist[i]);
    }
}

int main() 
{
    int graph[V][V] = 
	{
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
