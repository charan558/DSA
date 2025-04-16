#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
	int data;
	struct node* next;
}*top=0,*new,*temp;
int choice;
void main()
{
	printf("1-push  2-pop  3-display  4-exit\n");
	while(1)
	{
		printf("Enter your choice :");
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
			default:printf("INVALID\n");
		}
	}
}
void push()
{
	new=malloc(sizeof(struct node));
	printf("data to be inserted:");
	scanf("%d",&new->data);
	new->next=top;
	top=new;
}
void pop()
{
	if(top==0)
	{
		printf("STACK IS EMPTY\n");
	}
	else
	{
		temp=top;
		top=temp->next;
		free(temp);
	}
}
void display()
{
	if(top==0)
	{
		printf("STACK IS EMPTY\n");
	}
	else
	{
		printf("STACK DATA IS:\n");
		temp=top;
		while(temp!=NULL)
		{
			printf("%d  ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
		
