#include<stdio.h>
#include<stdlib.h>
struct node* create();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
int main()
{
	struct node* root=NULL;
	root=create();
	if(root==NULL)
	{
		return 0;
	}
	printf("Preorder traversal:");
	preorder(root);
	printf("\n");
	printf("Postorder traversal:");
	postorder(root);
	printf("\n");
	printf("Inorder traversal:");
	inorder(root);
	printf("\n");
	return 0;
}
struct node* create()
{
	int x;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->left=NULL;
	newnode->right=NULL;
	printf("Enter data -1 for no node:");
	scanf("%d",&x);
	if(x==-1)
	{
		return 0;
	}
	newnode->data=x;
	printf("Enter left child of %d:\n",x);
	newnode->left=create();
	printf("Enter right child of %d:\n",x);
	newnode->right=create();
	return newnode;
}
void inorder(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d  ",root->data);
	inorder(root->right);
}
void preorder(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d  ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d  ",root->data);
}
	
	
	

