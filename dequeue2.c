//c program to implement dequeue using linkedlist
#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue* next;
	struct queue* prev;
}*front,*temp,*q;
int value;
void enqueueF(int val)
{
	struct queue* p=(struct queue*)malloc(sizeof(struct queue));
	p->data=val;
	p->next=NULL;
	p->prev=NULL;
	if(front==NULL)
	front=p;
	else
	{
		temp=front;
		p->next=front;
		front->prev=p;
		front=p;
	}
}
void enqueueR(int val)
{
	struct queue* p=(struct queue*)malloc(sizeof(struct queue));
	p->data=val;
	p->next=NULL;
	p->prev=NULL;
	if(front==NULL)
	front=p;
	else
	{
		temp=front;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=p;
	}
}
void dequeueF()
{
	if(front==NULL)
	{
		printf("\nqueue is empty");
	}
	else
	{
		temp=front;
		front=front->next;
		front->prev=NULL;
		printf("\nThe value popped is %d",temp->data);
		free(temp);
	}
}
void dequeueR()
{
	if(front==NULL)
	{
		printf("\nqueue is empty");
	}
	else
	{
		temp=front;
		q=front;
		while(temp->next!=NULL)
		{
			q=temp;
			temp=temp->next;
		}
		printf("\nThe value popped is %d",temp->data);
		q->next=NULL;
		free(temp);
	}
}
void search(int val)
{
	int i,c=0;
	if(front==NULL)
	printf("\nqueue is empty");
	else
	{
		temp=front;
		while(temp->next!=NULL)
		{
			if(temp->data==val)
			{
				printf("\nvalue found");
				c=c+1;
			}
			temp=temp->next;
		}
		if(temp->data==val)
		{
			printf("\nvalue found");
			c=c+1;
		}
		if(c==0)
		printf("\nvalue not found");
	}
}
void display()
{
	int i;
	if(front==NULL)
	printf("\nqueue is empty");
	else
	{
		printf("\nqueue is :\n");
		temp=front;
		while(temp->next!=NULL)
		{
			printf("\t%d",temp->data);
			temp=temp->next;
		}
		printf("\t%d",temp->data);	
	}
}
void main()
{
	int ch;
	printf("1.enqueueF\n2.enqueueR\n3.dequeueF\n4.dequeueR\n5.search\n6.print\n\n");
	while(1)
	{
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("\nEnter the value to insert:");
				scanf("%d",&value);
				enqueueF(value);
				break;
			}
			case 2:
			{
				printf("\nEnter the value to insert:");
				scanf("%d",&value);
				enqueueR(value);
				break;
			}
			case 3:
			{
				dequeueF();
				break;
			}
			case 4:
			{
				dequeueR();
				break;
			}
			case 5:
			{
				printf("\nEnter the value to search:");
				scanf("%d",&value);
				search(value);
				break;
			}
			case 6:
			{
				display();
				break;
			}
			default:
			{
				exit(0);
				break;
			}
		}
	}
}