#include <stdio.h>
#include <stdlib.h>
void inorder();
struct node {
	int data;
	struct node *left, *right;
};
//create a new BST node
struct node* newNode(int item)
{
	struct node* new
		= (struct node*)malloc(sizeof(struct node));
	new->data = item;
	new->left = new->right = NULL;
	return new;
}

// insert

struct node* insert(struct node* node, int key)
{
	// If the tree is empty, return a new node
	if (node == NULL)
		return newNode(key);

	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);

	return node;
}

//search
struct node* search(struct node* root, int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->data == key)
		return root;

	// Key is greater than root's key
	if (root->data < key)
		return search(root->right, key);

	// Key is smaller than root's key
	return search(root->left, key);
}

int main()
{
	struct node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	inorder(root);

	// Key to be found
	int key;
	printf("enter the key");
	scanf("%d",&key);

	// Searching in a BST
	if (search(root, key) == NULL)
		printf("%d not found\n", key);
	else
		printf("%d found\n", key);

	
	return 0;
}
void inorder(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

