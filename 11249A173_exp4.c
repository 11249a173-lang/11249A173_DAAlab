#include<stdio.h>
struct Item
{
	int profit;
	int weight;
	float ratio;
};
int main()
{
	int n,capacity;
	int i,j;
	float totalprofit=0;
	printf("enter no.of items:");
	scanf("%d",&n);
	struct Item item[n];
	printf("Enter profit of each item:\n");
    for(i = 0; i < n; i++)
	{
	   scanf("%d", &item[i].profit);
    }
	printf("Enter weight of each item:\n");
	for(i = 0; i < n; i++)
	{
	   scanf("%d", &item[i].weight);
	}
	for(i = 0; i < n; i++)
	{
	   item[i].ratio = (float)item[i].profit / item[i].weight;
	}
	printf("enter knapsack capacity:");
	scanf("%d",&capacity);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
	   	{
			if(item[i].ratio<item[j].ratio)
			{
				struct Item temp=item[i];
				item[i]=item[j];
				item[j]=temp;
			}
		}
	}
	printf("\n Items selected:");
	for(i=0;i<n;i++)
	{
		if(capacity>=item[i].weight)
		{
			printf("item with profit %d and weight %d taken fully\n",item[i].profit,item[i].weight);
			totalprofit += item[i].profit;
			capacity-=item[i].weight;
	    }
	    else
	    {
			printf("Item with profit %d and weight %d taken partially\n",item[i].profit,item[i].weight);
			totalprofit +=item[i].profit*((float)capacity/item[i].weight);
			break;
		}
	}
	printf("\n Maximum profit =%2f\n",totalprofit);
	return 0;
}
