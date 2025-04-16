#include<stdio.h>
#include<stdlib.h>
void insrtbeg();
void display();
void position();
void insrtend();
struct node
{
	int data;
	struct node* next;
	struct node* prev;
}*head,*ptr,*ptr1,*new;
int choice=1,count=0,pos,i;
int main()
{
	head=NULL;
	while (choice)
	{
		new=malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&new->data);
		if(head==NULL)
		{
			new->next=NULL;
			new->prev=NULL;
			head=new;
			ptr=head;
		}
		else
		{
			ptr->next=new;
			new->prev=ptr;
			new->next=NULL;
			ptr=new;
		}
		count++;
		printf("To continue 1 To exit 0:");
		scanf("%d",&choice);
	}
	while(1)
	{
		printf("1-for insertatbeg 2-for display 3-for position 4-for insert end 5-for Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insrtbeg();
				break;
			case 2: display();
				break;
			case 3: position();
				break;
			case 4: insrtend();
				break;
			case 5: exit(0);
			default: printf("INVALID");
		}
	}
	printf(".................PROGRAMME END....................");
	
}
void insrtbeg()
{
	ptr=head;
	new=malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&new->data);
	if(head==NULL)
	{
		new->next=NULL;
		new->prev=NULL;
		head=new;
	}
	else
	{
		new->next=ptr;
		new->prev=NULL;
		ptr->prev=new;
		head=new;
	}
	count++;
}
void display()
{
	ptr=head;
	printf("All data nodes are:\n");
	while (ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}
void position()
{
	printf("Enter position:");
	scanf("%d",&pos);
	if(pos==1)
	{
		insrtbeg();
	}
	if(pos>1 && pos<=count)
	{
		ptr=head;
		new=malloc(sizeof(struct node));
		printf("Data to be inserted:");
		scanf("%d",&new->data);
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->next;
		}
		ptr1=ptr->next;
		new->prev=ptr;
		new->next=ptr1;
		ptr1->prev=new;
		ptr->next=new;
		count++;
	}
	if(pos>count)
	{
		printf("INVALID");
	}
}
void insrtend()
{
	ptr=head;
	if(head==NULL)
	{
		insrtbeg();
	}
	else
	{
		new=malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&new->data);
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		new->prev=ptr;
		ptr->next=new;
		new->next=NULL;
		count++;
	}
}

		
		
	
	
