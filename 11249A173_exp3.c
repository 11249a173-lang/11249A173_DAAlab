#include <stdio.h>
#define MAX 100
int firstFit(int items[], int n, int capacity)
{
    int bin_rem[MAX] = {0};
    int bins = 0;
    int i,j;
    for(i = 0; i < n; i++)
    {
        int placed = 0;
        for( j = 0; j < bins; j++)
        {
            if(bin_rem[j] >= items[i])
            {
                bin_rem[j] -= items[i];
                placed = 1;
                break;
            }
        }
        if(!placed)
        {
            bin_rem[bins] = capacity - items[i];
            bins++;
        }
    }
    return bins;
}
int firstFitDec(int items[], int n, int capacity)
{
	int i,j;
    for(i = 0; i < n-1; i++)
    {
        for( j = 0; j < n-i-1; j++)
        {
            if(items[j] < items[j+1])
            {
                int temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
    return firstFit(items, n, capacity);
}
int bestFit(int items[], int n, int capacity)
{
    int bin_rem[MAX] = {0};
    int bins = 0;
    int i,j;
    for( i = 0; i < n; i++)
    {
        int best = -1;
        int min_rem = capacity + 1;
        for( j = 0; j < bins; j++)
        {
            if(bin_rem[j] >= items[i] &&
               (bin_rem[j] - items[i]) < min_rem)
            {
                best = j;
                min_rem = bin_rem[j] - items[i];
            }
        }
        if(best != -1)
        {
            bin_rem[best] -= items[i];
        }
        else
        {
            bin_rem[bins] = capacity - items[i];
            bins++;
        }
    }
    return bins;
}
int main()
{
    int items[MAX], items_copy[MAX];
    int n, capacity;
    int i,j;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter %d item sizes: ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &items[i]);
        items_copy[i] = items[i]; 
    }
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);
    printf("\n=== BIN PACKING RESULTS ===\n");
    printf("Items: ");
    for( i = 0; i < n; i++)
        printf("%d ", items[i]);
    printf("\nBin Capacity: %d\n\n", capacity);
    printf("First Fit: %d bins\n", firstFit(items, n, capacity));
    printf("First Fit Decreasing: %d bins\n", firstFitDec(items_copy, n, capacity));
    printf("Best Fit: %d bins\n", bestFit(items, n, capacity));
    return 0;
}
