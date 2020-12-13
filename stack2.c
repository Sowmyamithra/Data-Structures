//c program to implement stack using linkedlist
#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack* next;
}*start,*temp,*q;
int value;
void push(int val)
{
	struct stack* p=(struct stack*)malloc(sizeof(struct stack));
	p->data=val;
	p->next=NULL;
	if(start==NULL)
	start=p;
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=p;
	}
}
void pop()
{
	if(start==NULL)
	{
		printf("\nstack is empty");
	}
	else
	{
		temp=start;
		q=start;
		while(temp->next!=NULL)
		{
			q=temp;
			temp=temp->next;
		}
		printf("\nThe value popped is : %d",temp->data);
		q->next=NULL;
		free(temp);
	}
}
void search(int val)
{
	int i,c=0;
	if(start==NULL)
	printf("\nstack is empty");
	else
	{
		temp=start;
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
	if(start==NULL)
	printf("\nstack is empty");
	else
	{
		printf("\nstack is :\n");
		temp=start;
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
	printf("1.INSERT\n2.DELETE\n3.SEARCH\n4.PRINT\n\n");
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
				push(value);
				break;
			}
			case 2:
			{
				pop();
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