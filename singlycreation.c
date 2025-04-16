#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*head=0,*temp;
int choice=1;
//creation of a singly list
int main()
{
	while(choice)
	{
		struct node* new=(struct node*)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&new->data);
		new->next=NULL;
		if(head==0)
		{
			head=temp=new;
		}
		else
		{
			temp->next=new;
			temp=new;
		}
		printf("DO YOU WANT TO CONTINUE (0-1)");
		scanf("%d",&choice);
	}
	struct node *crntnd=head,*nxtnd=head,*prevnd=NULL;
	while(nxtnd!=NULL)
	{
		nxtnd=nxtnd->next;
		crntnd->next=prevnd;
		prevnd=crntnd;
		crntnd=nxtnd;
	}
	head=prevnd;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}

}



		
	
