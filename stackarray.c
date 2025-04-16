#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
int stack[100],i,x,n,top=-1,choice;
int main()
{
	printf("Enter the size of stack:");
	scanf("%d",&n);
	while(1)
	{
		printf("1-push  2-pop  3-display  4-exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default:printf("INVALID");
		}
	}
}
void push()
{
	printf("Enter element:");
	scanf("%d",&x);
	if(top==n-1)
	{
		printf("STACK IS FULL\n");
	}
	else
	{
		top++;
		stack[top]=x;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("STACK IS EMPTY\n");
	}
	else
	{
		printf("Deleted element is=%d\n",stack[top]);
		top--;
	}
}
void display()
{
	if(top==-1)
	{
		printf("STACK IS EMPTY\n");
	}
	else
	{
		printf("STACK ELEMENTS ARE:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d  ",stack[i]);
		}
		printf("\n");
	}
}


