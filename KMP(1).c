#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int F[10];
void Failure_Function(char P[],int m)
{
	int i=1,j=0;
	F[0]=0;
	while(i<m)
	{
		if(P[i]==P[j])
		{
			F[i]=j+1;
			i=i+1;
			j=j+1;
		}
		else if(j>0)
		{
			j=F[j-1];
			//i=i+1;
		}
		else
		{
			F[i]=0;
			i=i+1;
		}
	}
	
}
int KMP(char S[],char P[],int n,int m)
{
	int i,j;
	i=0;
	j=0;
	while(i<n)
	{
		if(P[j]==S[i])
		{
			if(j==m-1)
			return(i-j);
			else
			{
				i=i+1;
				j=j+1;
			}
		}
		else if(j>0)
		{
			j=F[j-1];
		}
		else
		{
			i=i+1;
		}
	}
}
void main()
{
	int n,m,i;
	char S[100],P[100];
	printf("\nEnter String:");
	scanf("%s",S);
	printf("\nEnter Pattern:");
	scanf("%s",P);
	n=strlen(S);
	m=strlen(P);
	Failure_Function(P,m);
	i=KMP(S,P,n,m);
	printf("\nThe pattern is found at position %d",i);
}