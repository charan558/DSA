#include<stdio.h>
#include<stdlib.h>
void insertion();
void deletion();
void display();
int choice,i,item,count=0,pos;
struct node
{
int data;
struct node *next;
}*tail,*new,*temp,*ptr;
int main()
{
	tail=NULL;
	printf("\n select menu\n");
	while(1)
	{
		printf("1.INSERTION  2.DELETION  3.Display  4.Exit\n");
		printf("\nEnter ur choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insertion();
				break;
			case 2: deletion();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("\nWrong choice.");
		}/*end of switch*/
	}/*end of while*/
}/*end of main*/
void insertion()
{
	new=malloc(sizeof(struct node));
	printf("\nEnter the item: ");
	scanf("%d",&new->data);
	if(tail==NULL)
	{
		tail=new;
		tail->next=new;
		count++;
	}
	else
	{
		printf("1-start  2-position  3-end\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		if(choice==1)
		{
			new->next=tail->next;
			tail->next=new;
			count++;
		}
		if(choice==2)
		{
			printf("Enter your position:");
			scanf("%d",&pos);
			if(pos==1)
			{
				new->next=tail->next;
				tail->next=new;
				count++;
			}
			else if(pos>1 && pos<=count)
			{
				temp=tail->next;
				for(i=1;i<pos-1;i++)
				{
					temp=temp->next;
				}
				new->next=temp->next;
				temp->next=new;
				count++;
			}
			else
			{
				printf("POSITION INVALID\n");
			}
		}
		if(choice==3)
		{
			
			new->next=tail->next;
			tail->next=new;
			tail=new;			
			count++;
		}
	}
}
void deletion()
{
	if(tail==NULL)
	{
		printf("CIRCULAR LIST IS EMPTY\n");
	}
	//temp=tail->next;
/*	if(temp==tail->next)
	{
		tail=0;
		free(temp);
	}*/
	else
	{
		temp=tail->next;
		printf("1-start  2-position  3-end\n");
		printf("Enter your choice ");
		scanf("%d",&choice);
		if(choice==1)
		{
			if(tail==temp)
			{
				tail=0;
			}
			else 
			{
				tail->next=temp->next;
			}
			free(temp);
			count--;
		}
		if(choice==2)
		{
			printf("Enter position:");
			scanf("%d",&pos);
			if(pos==1)
			{
				if(tail==temp)
				{
					tail=0;
				}
				else 
				{
					tail->next=temp->next;
				}
				free(temp);
				count--;
			}
			else if(pos>1 && pos<=count)
			{
				for(i=1;i<pos-1;i++)
				{
					temp=temp->next;
				}
				ptr=temp->next;
				temp->next=ptr->next;
				free(ptr);
				if(pos==count)
				{
					tail=temp;
				}
				count--;
			}
			else 
			{
				printf("INVALID POSITION\n");
			}
		}
		if(choice==3)
		{
			if(tail==temp)
			{
				tail=NULL;
				free(temp);
			}
			else
			{
				while(temp->next!=tail)
				{
					temp=temp->next;
				}
				ptr=temp->next;
				temp->next=ptr->next;
				tail=temp;
				free(ptr);
				count--;
			}
		}
	}
}
void display()
{
	if(tail==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
		printf("CIRCULAR LIST IS:\n");
		temp=tail->next;
		while(temp!=tail)
		{
			printf("%d  ",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
		printf("\n");
	}
}
		

		
					
				
			
			
