#include<stdio.h>
int tree[8];
void root(char);
void insert_left(char,int);
void insert_right(char,int);
void display();
void inorder(int);
void preorder(int);
void postorder(int);
void main()
{
	root('A');
	insert_left('B',0);
	insert_right('C',0);
	insert_left('D',2);
	insert_right('E',2);
	display();
	printf("\n"); // output:A B C - - D E -
	printf("Inorder Traversal: ");
	inorder(0);
	printf("\n"); 
	printf("Preorder Traversal: ");
	preorder(0);
	printf("\n"); 
	printf("Postorder Traversal: ");
	postorder(0);
	printf("\n"); 
}
void root(char key)
{
	if(tree[0]!='\0')
	{
		printf("It already had a root\n");
	}
	else
	{
		tree[0]=key;
	}
}
void insert_left(char key,int i)//i->index of parent node
{
	if(tree[i]=='\0')
	{
		printf("We cannot insert child at %d because no parent found\n",(i*2)+1);
	}
	else
	{
		tree[(i*2)+1]=key;
	}
}
void insert_right(char key,int i)//i->index of parent node
{
	if(tree[i]=='\0')
	{
		printf("We cannot insert child at %d because no parent found\n",(i*2)+2);
	}
	else
	{
		tree[(i*2)+2]=key;
	}
}
void display()
{
	int j;
	for(j=0;j<8;j++)
	{
		if(tree[j]!='\0')
		{
			printf("%c ",tree[j]);
		}
		else
		{
			printf("- ");
		}
	}
}
void inorder(int i)
{
	if(tree[i]!='\0')
	{
		inorder((i*2)+1);
		printf("%c",tree[i]);
		inorder((i*2)+2);
	}
}
void preorder(int i)
{
	if(tree[i]!='\0')
	{
		printf("%c",tree[i]);
		preorder((i*2)+1);
		preorder((i*2)+2);
	}
}
void postorder(int i)
{
	if(tree[i]!='\0')
	{
		postorder((i*2)+1);
		postorder((i*2)+2);
		printf("%c",tree[i]);
	}
}

	
