#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


void traverse();
void deletion();
void insertion();

int choice,i,pos,item;







struct node

{
	int data;
	struct node *link;
}*header,*ptr,*ptr1,*new;


void main()
{
	header=NULL;
	ptr=header;
	printf("Menu\n");
	printf("\n 1.Insertion\n 2.Deletion\n 3.Traverse\n 4.Search\n 4.Exit\n");
	while(1)
	{
		printf("\nEnter ur choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insertion();
				break;
			case 2: deletion();
				break;
			case 3: traverse();
				break;
			case 4: exit(0);
			default: printf("\nWrong choice");
		}
	}
}




void insertion()
{
	new=malloc(sizeof(struct node));
	printf("\nEnter the item to be inserted: ");
	scanf("%d",&item);
	new->data=item;
	if(header==NULL)
	{
		new->link=NULL;
		header=new;
	}
	else
	{
		printf("\nEnter the place to insert the item: ");
		printf("1.Start\n 2.Middle\n 3.End\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			new->link=header;
			header=new;
		}
		if(choice==2)
		{
			ptr=header;
			printf("\nEnter the position to place an item: ");
			scanf("%d",&pos);
			for(i=1;i<pos-1;i++)
			{
				ptr=ptr->link;
			}
			new->link=ptr->link;
			ptr->link=new;
		}
		if(choice==3) 
		{
			ptr=header;
			while(ptr->link!=NULL)
			{
				ptr=ptr->link;
			}
			new->link=NULL;
			ptr->link=new;
		}
	}
}
void deletion()
{
	ptr=header;
	if(header==NULL)
	{
		printf("\nThe list is empty");
	}
	else
	{
		printf("\n1.Start \n2.Middle \n3.End");
		printf("\nEnter the place to delete the element from list:\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\nThe deleted item from the list is: %d",ptr->data);
			header=header->link;
		}
		if(choice==2)
		{
			printf("\nEnter the position to delete the element from the list");
			scanf("%d",&pos);
			for(i=0;i<pos-1;i++)
			{
				ptr1=ptr;
				ptr=ptr->link;
			}
			printf("\nThe deleted element is: %d",ptr->data);
			ptr1->link=ptr->link;
		}

		if(choice==3) 
		{
			while(ptr->link!=NULL)
			{
				ptr1=ptr;
				ptr=ptr->link;
			}//while
			printf("\nThe deleted element from the list is: %d",ptr->data);
			ptr1->link=NULL;
		}
	}
}
void traverse()
{
	if(header==NULL)
		printf("List is empty\n");
	else
	{
		printf("\nThe elements in the list are: ");
		for(ptr=header;ptr!=NULL;ptr=ptr->link)
		{
			printf(" %d",ptr->data);
		}
	}
}
