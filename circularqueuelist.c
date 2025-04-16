#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
struct node
{
	int data;
	struct node* next;
}*front=0,*rear=0,*new,*temp;
int choice;
void main()
{
	printf("1-enqueue  2-dequeue  3-display  4-exit\n");
	while(1)
	{
		printf("Enter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: enqueue();
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default:printf("INVALID\n");
		}
	}
}
void enqueue()
{
	new=malloc(sizeof(struct node));
	printf("data to be inserted:");
	scanf("%d",&new->data);
	if(front==0 && rear==0)
	{
		front=rear=new;
		//rear->next=front;
		
	}
	else
	{
		rear->next=new;
		rear=new;
	}
	rear->next=front;
}
void dequeue()
{
	temp=front;
	if(front==0 && rear==0)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else if(front==rear)
	{
		front=rear=0;
		free(temp);
	}
	else
	{
		front=front->next;
		rear->next=front;
		free(temp);
	}
}
void display()
{
	if(front==0 && rear==0)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		printf("QUEUE DATA IS:\n");
		temp=front;
		while(temp->next!=front)
		{
			printf("%d  ",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
		printf("\n");
	}
}
		
