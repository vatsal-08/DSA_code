#include<stdio.h>
#include<stdlib.h>
int size = 0;
void swap(int *x, int *y)
{
  int t = *y;
  *y = *x;
  *x = t;
}
void maxheapify(int arr[], int size, int i)
{
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[l] > arr[large])
    {large = l;}
    if (r < size && arr[r] > arr[large])
    {  large = r;}
    if (large != i)
    {
      swap(&arr[i], &arr[large]);
      maxheapify(arr, size, large);
    }
} 
void minheapify(int arr[], int size, int i)
{
    int  small = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[l] < arr[small])
    { small = l;}
    if (r < size && arr[r] < arr[small])
    {small = r;}
    if (small != i)
    {
      swap(&arr[i], &arr[small]);
      minheapify(arr, size, small);
    }
}
void buildminheap(int arr[], int n) 
{
    int startidx = (n / 2) - 1; 
    for (int i = startidx; i >= 0; i--) 
    { 
        minheapify(arr, n, i); 
    }
}
void buildmaxheap(int arr[], int n) 
{ 
    int startidx = (n / 2) - 1;
    for (int i = startidx; i >= 0; i--) 
    { 
        maxheapify(arr, n, i); 
    }
}
void insertminheap(int arr[], int new)
{
  if (size == 0)
  {
    arr[0] = new;
    size += 1;
  }
  else
  {
    arr[size] = new;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      minheapify(arr, size, i);
    }
  }
}
void insertmaxheap(int arr[], int new)
{
  if (size == 0)
  {
    arr[0] = new;
    size += 1;
  }
  else
  {
    arr[size] = new;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      maxheapify(arr, size, i);
    }
  }
}
void printHeap(int arr[], int n)
{ 
    
    for (int i = 0; i < n; ++i) 
    {printf("%d\t",arr[i]);}
    printf("\n"); 
} 
int main() 
{  	int c=1,n;
	while (c==1)
	{
		size=0;
		int choice,d;
		printf("\n----------MAIN MENU ----------\n");
		printf("CHOICES ARE AS FOLLOW\n");
		printf("1) press 1. Create a minheap from a sequence of integers. \n");
		printf("2) press 2. Create a maxheap from a sequence of integers. \n");
		printf("3) press 3. Convert any random arr into a minheap or maxheap. \n");
		printf("4) press 4. Heapsort using minheaps and maxheaps. \n");
		scanf("%d",&choice);
		if(choice==1)
		{
			n=100;
			int arr[n];
			int t,d;
			printf("how many element you want to enter--");
			scanf("%d",&t);
			for(int i=0;i<t;i++)
			{
				printf("enter the element--");
				scanf("%d",&d);
				insertminheap(arr, d);
			}
			printf("Array representation of  Min Heap is:\n" );
			printHeap(arr,size);
		}
		else if(choice==2)
		{
			n=100;
			int arr[n];
			int t,d;
			printf("how many element you want to enter--");
			scanf("%d",&t);
			for(int i=0;i<t;i++)
			{
				printf("enter the element--");
				scanf("%d",&d);
				insertmaxheap(arr, d);
			}
			printf("Array representation of Max Heap is:\n" );
			printHeap(arr,size); 
		}
		else if(choice==3)
		{
			printf("enter the length of array --");
			scanf("%d",&n);
			int arr[n];
			int t,i,d;
			
			for(int i=0;i<n;i++)
			{
				printf("enter the element of array --");
				scanf("%d",&arr[i]);
			}
			printf("prees 1 for min heap or 2 for max heap ---");
			scanf("%d",&t);
			 if(t==1)
			 {
				 buildminheap(arr,n);
			 }
			 else
			 {
				 buildmaxheap(arr, n);
			 }
			 printf("Array representation of Heap is:\n" );
			 printHeap(arr,n); 
		}
		else if(choice==4)
		{
			n=100;
			int arr[n];
			int w,d;
			printf("prees 1 to sort with min heap or 2 with max heap----");
			scanf("%d",&w);
			if(w==1)
			{
				int arr[n];
				int t,i,d;
				printf("how many element you want to enter to sort--");
				scanf("%d",&t);
				for(int i=0;i<t;i++)
				{
					printf("enter the element--");
					scanf("%d",&d);
					insertminheap(arr, d);
				}
				for (int i = size - 1; i >= 0; i--)
				{
					swap(&arr[0], &arr[i]);
					minheapify(arr, i, 0); 
				}
				printf("sorted element using Heap sort with min heap is:\n" );
				printHeap(arr,size);
			}
			else
			{
				int arr[n];
				int t,i,d;
				printf("how many element you want to enter sort--");
				scanf("%d",&t);
				for(int i=0;i<t;i++)
				{
					printf("enter the element--");
					scanf("%d",&d);
					insertmaxheap(arr, d);
				}
				for (int i = size - 1; i >= 0; i--) 
				{
					swap(&arr[0], &arr[i]);
					maxheapify(arr, i, 0);
				}
				printf("sorted element using Heap sort with max heap is:\n" );
				printHeap(arr,size);
		}
	}
	printf("\nto go to main menu prees 1 else press 0--");
	scanf("%d",&c);
	}
	return 0;
}