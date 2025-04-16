#include<stdio.h>
struct node{
    int data;
    struct node *next;
}*header,*new,*temp;
void main()
{
while(choice)
{
	int choice;
	printf("1.insertatbegin   2.display   3.exit\n");
	printf("enter ur choice");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:insertatbeg();
	break;
	case 2:display();
	break;
	case 3:exit(0);
	break;---
	} 	
}
}
struct node create
{
	new=malloc(sizeof(struct node));
    printf("enter the data");
    scanf("%d",&new->data);
    return new;
  }
void insertatbeg()
{ 
	new=create();
    if(header==NULL)
    {
        new->next=NULL;
        header=new;
    }
    else{
        new->next=header;
        header=new;
    }
}
void display()
{
    for(temp=header;temp->next!=NULL;temp=temp->next)
    {
        printf("%d",temp->data);
    }
}
