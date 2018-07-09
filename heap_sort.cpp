#include<iostream>
using namespace std;

/*
*  functions to get the parent,left child or right child of an element 
*/
int parent(int i)
{
	return i >> 1;
}

int left(int i)
{
	return i << 1;
}

int right(int i)
{
	return (i << 1) + 1;
}


/*
*  the max_heapify function compare the root element a[i] with its left child and right child 
*  and it makes the largest element be the root element 
*/
void max_heapify(int* a,int i,int n)
{
	int largest = 0;

	int left_index = left(i);
	int right_index = right(i);

	if (left_index<=n&&a[left_index]>a[i])
	{
		largest = left_index;
	}
	else
	{
		largest = i;
	}

	if (right_index<=n&&a[right_index]>a[largest])
	{
		largest = right_index;
	}

	if (largest != i)
	{
		int temp;
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		max_heapify(a, largest, n);
	}
}


/*
* since the heap size is n ,element indexed 2/n,2/n+1...n are the leaves 
* the function build a max heap with the array input 
*/
void build_max_heap(int *a,int n)
{
	for (int i = n/ 2; i >= 1; i--)
	{
		max_heapify(a, i, n);
	}
}


/*
* function of the heap sort algorithm
*/
void heap_sort(int* a,int &n)
{ 
	build_max_heap(a, n);
	for (int i = n; i >= 2; i--)
	{
		int temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		n -= 1;
		max_heapify(a, 1,n);
	}
}


void max_heap_sort_demo()
{
	//we make the index starts from 1 instead of 0
	int a[11] = { 0,16,4,10,14,7,9,3,2,8,1 };
	int size = 10;
	heap_sort(a, size);
	for (int i = 1; i < 11; i++)
	{
		cout << a[i] << " ";
	}
}
