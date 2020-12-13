//c program to implement queue using linkedlist
#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue* next;
}*front,*temp,*q;
int value;
void enqueue(int val)
{
	struct queue* p=(struct queue*)malloc(sizeof(struct queue));
	p->data=val;
	p->next=NULL;
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
void dequeue()
{
	if(front==NULL)
	{
		printf("\nqueue is empty");
	}
	else
	{
		temp=front;
		front=front->next;
		printf("\nThe value popped is %d",temp->data);
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
	printf("1.ENQUEUE\n2.DEQUEUE\n3.SEARCH\n4.PRINT\n\n");
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
				enqueue(value);
				break;
			}
			case 2:
			{
				dequeue();
				break;
			}
			case 3:
			{
				printf("\nEnter the value to search:");
				scanf("%d",&value);
				search(value);
				break;
			}
			case 4:
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