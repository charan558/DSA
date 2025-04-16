#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
struct node
{
	int data;
	struct node*next;
}*rear=0,*front=0,*new,*temp;
int choice;
int main()
{
	printf(".....MENU.....\n");
	while(1)
	{
		printf("1-for enqueue  2-for dequeue  3-for display  4-for exit\n");
		printf("Enter your choice:");
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
			default:printf("INVALID");
		}
	}
}
void enqueue()
{
	new=malloc(sizeof(struct node));
	printf("Enter data to be inserted:");
	scanf("%d",&new->data);
	if(rear==0)
	{
		front=rear=new;
		rear->next=front;
	}
	else
	{
		rear->next=new;
		rear=new;
		rear->next=front;
	}
}
void display()
{
	temp=front;
	if(front==0 && rear==0)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		printf("QUEUE IS :\n");
		while(temp->next!=front)
		{
			printf("%d  ",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
		printf("\n");
	}
}
void dequeue()
{
	temp=front;
	if(front==0 && rear==0)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else if (front==rear)
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
