#include<stdio.h>
#include<stdlib.h>
void dltbeg();
void display();
void position();
void dltend();
struct node
{
	int data;
	struct node* next;
	struct node* prev;
}*head,*ptr,*ptr1,*ptr2,*new;
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
		printf("1-dltbeg 2-display 3-dltpos 4-dltend 5-Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: dltbeg();
				break;
			case 2: display();
				break;
			case 3: position();
				break;
			case 4: dltend();
				break;
			case 5: exit(0);
			default: printf("INVALID");
		}
	}
	printf(".................PROGRAMME END....................");
	
}
void dltbeg()
{
	ptr=head;
	if(head==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else if(ptr==head)
	{
		head=NULL;
		free(ptr);
		count--;
	}
	else
	{
		ptr1=ptr->next;
		ptr1->prev=NULL;
		head=ptr1;
		free(ptr);
		count--;
	}
}
void display()
{
	ptr=head;
	if(head==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
	}
}
void position()
{
	printf("Enter position:");
	scanf("%d",&pos);
	if(pos==1)
	{
		dltbeg();
	}
	else if(pos>1 && pos<count)
	{
		ptr=head;
		for(i=1;i<pos-1;i++)
		{
			ptr=ptr->next;
		}
		ptr1=ptr->next;
		ptr2=ptr1->next;
		ptr->next=ptr2;
		ptr2->prev=ptr1;
		free(ptr1);
		count--;
	}
	else
	{
		printf("At the position %d there is no node present\n",pos);
	}
}
void dltend()
{
	if(head==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else if(ptr==head)
	{
		head=NULL;
		free(ptr);
		count--;
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr1=ptr->prev;
		ptr1->next=NULL;
		free(ptr);
		count--;
	}
}
