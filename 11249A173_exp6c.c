#include <stdio.h>
#include <limits.h>

#define V 3

void floyds(int b[V][V]) 
{
    int i, j, k;
    for (k = 0; k < V; k++) 
	{
        for (i = 0; i < V; i++) 
		{
            for (j = 0; j < V; j++) 
			{
                if (b[i][k] != INT_MAX && b[k][j] != INT_MAX) 
				{
                    if (b[i][j] > b[i][k] + b[k][j]) 
					{
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < V; i++) 
	{
        printf("Minimum Cost With Respect to Node: %d\n", i);
        for (j = 0; j < V; j++) 
		{
            if (b[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int i,j;
	int b[V][V];
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            b[i][j] = (i == j) ? 0 : INT_MAX;

    b[0][1] = 10;
    b[1][2] = 15;
    b[2][0] = 12;

    floyds(b);
    return 0;
}
