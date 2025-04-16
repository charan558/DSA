#include<stdio.h>
void quicksort();
//int partition();
void swap();
void main()
{
	int n,i;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n-1);
	printf("Array after sorting is:");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void quicksort(int arr[],int low,int high)
{
	int start,end,pivot;
	if(low<high)
	{
		start=low;
		end=high;
		pivot=low;
		while(start<end)
		{
			while(arr[start]<=arr[pivot])
			{
				start++;
			}
			while(arr[end]>arr[pivot])
			{
				end--;
			}
			if(start<end)
			{
				swap(&arr[start],&arr[end]);
			}
		}
	
		swap(&arr[end],&arr[pivot]);
		quicksort(arr,low,end-1);
		quicksort(arr,end+1,high);
	}
}
void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
} 			
