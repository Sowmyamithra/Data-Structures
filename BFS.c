#include<stdio.h>
#include<stdlib.h>
int QUEUE[100],f=-1,r=-1;
void enqueue(int x)
{
	if(r==99)
	printf("\nQueue is Full");
	else
	{
		r=r+1;
		QUEUE[r]=x;
	}
}
void dequeue()
{
	if((f!=-1 && r!=-1) || f<=r)
	{
		f=f+1;
	}
}
void main()
{
	int graph[10][10],n,i,j,ct=0,v,x,vertices[10],visited[10]={1,1,1,1,1,1,1,1,1,1};
	printf("\nEnter the number of vertices of G:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix of graph");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}

	}
	printf("\nThe adjacency matrix of given graph:\n");
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("\t%d",graph[i][j]);
			}
			printf("\n");
		}
	}
	printf("\nEnter the starting vertex:");
	scanf("%d",&v);
	
	/*status=1 => ready;status=2 => need to be processed;status=3 => processed*/
	while(r>=f)
	{
		enqueue(v);
		for(i=0;i<n;i++)
		{
			if(graph[v][i]==1)	
			{
				if(visited[i]==1)
				{
					enqueue(i);
					visited[i]=2;
				}
			}
		}
		vertices[ct]=v;
		ct++;
		dequeue();
		visited[v]=3;
		while(visited[QUEUE[f]]==3 && f<=r)
		{
			f=f+1;
		}
		v=QUEUE[f];
	}
	printf("BFS:\n");
	for(i=0;i<ct;i++)
	printf("\t%d",vertices[i]);
}