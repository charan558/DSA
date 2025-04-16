#include<stdio.h>
void merge_sort();
void merge();
void main()
{
    int n, i;
    printf("Enter the size : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements : \n");
    for(i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);
    printf("Sorted array of the entered array : ");
    for(i = 0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void merge_sort(int a[],int low, int high)
{
    if(low<high)
    {
        int mid =(low + high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[],int low,int mid,int high)
{
    int i = low;
    int j = mid+1;
    int k = low;
    int b[100];
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
         {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
   if(i>mid)
   {
   	while(j<=high)
    	{
    	    b[k++] = a[j++];
    	}
    }
    else 
    {
    	while(i<=mid)
   	 {
   	     b[k++] = a[i++];
   	 }
    }
    for(k = low;k<=high;k++)
    {
        a[k] = b[k];
    }
}
