#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void traverse();
void deletion();
void insertion();
int choice,i,pos,cnt=0;
struct node
{
	int data;
	struct node *next;
}*header,*ptr,*ptr1,*new,*ptr2;
void main()
{
	header=NULL;
	printf("Menu\n");
	printf("\n 1.Insertion\n 2.Deletion\n 3.Traverse\n 4.Exit\n");
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
	scanf("%d",&new->data);
	if(header==NULL)
	{
		new->next=NULL;
		header=new;
		cnt++;
	}
	else
	{
		printf("\nEnter the place to insert the item: ");
		printf("1.Start\n 2.Middle\n 3.End\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			new->next=header;
			header=new;
			cnt++;
		}
		if(choice==2)
		{
			ptr=header;
			printf("\nEnter the position to place an item: ");
			scanf("%d",&pos);
			if(pos==1)
			{
				new->next=header;
				header=new;
				cnt++;
			}
			else if(pos>1 && pos<=cnt)
			{
			
				for(i=1;i<pos-1;i++)
				{
					ptr=ptr->next;
				}
				ptr1=ptr->next;
				ptr->next=new;
				new->next=ptr1;
				cnt++;
			}
			else 
			{
				printf("Invalid position\n");
			}
		}
		if(choice==3) 
		{
			ptr=header;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new;
			new->next=NULL;
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
			header=header->next;
			cnt--;
			free(ptr);
		}
		if(choice==2)
		{
			printf("\nEnter the position to delete the element from the list");
			scanf("%d",&pos);
			if(pos==1)
			{
				printf("\nThe deleted item from the list is: %d",ptr->data);
				header=header->next;
				cnt--;
				free(ptr);
			}
			else if(pos>1 && pos<=cnt)
			{
			
				for(i=1;i<pos-1;i++)
				{
					ptr=ptr->next;
				}
				ptr1=ptr->next;
				ptr->next=ptr1->next;
				printf("\nThe deleted item from the list is: %d",ptr1->data);
				free(ptr1);
				cnt--;
			}
			else
			{
				printf("There is no data at position %d\n",pos);
			}
		}
		if(choice==3) 
		{
			if(ptr->next==NULL)
			{
				printf("\nThe deleted element from the list is: %d",ptr->data);
				header=NULL;
				free(ptr);
			}
			else
			{
				while(ptr->next!=NULL)
				{
					ptr1=ptr;
					ptr=ptr->next;
				}//while
				printf("\nThe deleted element from the list is: %d",ptr->data);
				ptr1->next=NULL;
				free(ptr);
			}
			cnt--;
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
		for(ptr=header;ptr!=NULL;ptr=ptr->next)
		{
			printf(" %d",ptr->data);
		}
	}
}
