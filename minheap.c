g#include<stdio.h>
#include<stdlib.h>
void buildheap();
void heapify();
void swap();
void delete();
void insert();
int i,val;
void display();
int main()
{
	int n;
	printf("enter the size:\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements:\n");
        for(i=0;i<n;i++)
        {
     		scanf("%d",&arr[i]);
	}
	buildheap(arr,n);
	printf("After min heap:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
	//printheap(arr,n);
	int choice;
	while(1)
	{
		printf("Enter 1-insertion 2-deletion 3-display 4-exit:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter insertion value:");
				scanf("%d",&val);
				insert(arr,n,val);
				n=n+1;
				break;
			case 2: delete(arr,n);
				n=n-1;
				break;
			case 3: display(arr,n);
				break;
			case 4:exit(0);
		}
	}
	
}

void buildheap(int arr[],int n)
{
//index of non leaf node
	int nln=(n/2)-1;
	for(i=nln; i>=0;i--){
		heapify(arr,n,i);
	}
}

void heapify( int arr[],int n,int i){
	int lowest=i;
	int left=(2*i)+1;
	int right=(2*i)+2;
	if(left<n && arr[left]<arr[lowest]){
		lowest=left;
	}

	if(right<n && arr[right]<arr[lowest]){
		lowest=right;
	}

	if(lowest!=i){
		swap(&arr[i],&arr[lowest]);
	
	heapify(arr,n,lowest);
	}
}

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
}
void insert(int arr[],int n,int value)
{
	int parent;
	n=n+1;
	arr[n-1]=val;
	i=n-1;
	while(i>0)
	{
		parent=(i-1)/2;
		if(arr[parent]>arr[i])
		{
		       swap(&arr[parent],&arr[i]);
		       i=parent;
	       }
	       else
	       {
	       	i=i-1;
	       }
	}
	/*printf("After Inserting:\n");
	for(int i=0;i<n;i++){
		printf("%d  ",arr[i]);
	}
	printf("\n");*/
}
void delete(int arr[],int n)
{
	swap(&arr[0],&arr[n-1]);
	n--;
	buildheap(arr,n);
}
	




