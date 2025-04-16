#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
int queue[100],n,choice,x,rear=-1,front=-1,i;
int main()
{
	printf("Enter the size:");
	scanf("%d",&n);
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
			default: printf("INVALID");
		}
	}
}
void enqueue()
{
	printf("Entrer element to be inserted:");
	scanf("%d",&x);
	if(rear==n-1)
	{
		printf("QUEUE IS FULL YOU CAN NOT INSERT\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=x;
	}
	else
	{
		rear++;
		queue[rear]=x;
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else if(front==rear)
	{
		printf("Deleted element is %d\n",queue[front]);
		front=rear=-1;
	}
	else
	{
		printf("Deleted element is %d\n",queue[front]);
		front++;
	}
}
void display()
{
	if(front==-1 && rear==-1)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		printf("QUEUE ELEMENTS ARE:\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d  ",queue[i]);
		}
		printf("\n");
	}
}
