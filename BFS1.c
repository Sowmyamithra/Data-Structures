//adjacency list representation of graphs (BFS)
#include<stdio.h>
#include<stdlib.h>
struct graph
{
	int val;
	struct graph* next;
}*G[10],*last;
int QUEUE[100],f=-1,r=-1;
void enqueue(int x)
{
	if(r==99)
	printf("\nQueue is Full");
	if(f==-1 && r==-1)
	{
		f=f+1;
		r=r+1;
	}
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
void create(struct graph* G[],int n)
{
	int i,j,m,data;
	for(i=0;i<n;i++)
	{
		printf("\nenter the number of vertices adjacent to vertex %d :",i);
		scanf("%d",&m);
		for(j=0;j<m;j++)
		{
			printf("\nEnter the vertex to be inserted:");
			scanf("%d",&data);
			struct graph* p=(struct graph*)malloc(sizeof(struct graph));
			p->val=data;
			p->next=NULL;
			if(G[i]==NULL)
				G[i]=p;
			else
			{
				last=G[i];
				while(last->next!=NULL)
					last=last->next;
				last->next=p;
			}
		}
	}
}
void display(struct graph* G[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		last=G[i];
		printf("\nThe vertices adjacent to %d are :\n",i);
		while(last->next!=NULL)
		{
			printf("\t%d",last->val);
			last=last->next;
		}
		printf("\t%d",last->val);
	}
}
void main()
{
	int n,i,v,ct,visited[10]={1,1,1,1,1,1,1,1,1,1},result[10],index=0;
	printf("\nEnter the number of vertices of graph:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	G[i]=NULL;
	create(G,n);
	display(G,n);
	printf("\nEnter the starting vertex:");
	scanf("%d",&v);
	while(r>=f)
	{
		enqueue(v);
		last=G[v];
		while(last!=NULL)
		{
			if(visited[last->val]==1)
			{
				enqueue(last->val);
				visited[last->val]=2;
			}
			last=last->next;
			
		}
		result[index]=v;
		index=index+1;
		dequeue();
		visited[v]=3;
		while(visited[QUEUE[f]]==3 && f<=r)
			f=f+1;
		v=QUEUE[f];
	}
	printf("BFS:\n");
	for(i=0;i<index;i++)
	printf("\t%d",result[i]);
}