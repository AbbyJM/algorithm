#include<iostream>
#include<time.h>
using namespace std;

//the merge_sort algorithm

/*
 *  param  a ,the (sub)array to be sorted
 *  param sorted,the array where we place the sorted array elements
 *  param start,the start index of the (sub)array
 *  param mid,the middle index of the (sub)array
 *  param end,the end index of the (sub)array
 */
void MERGE(int* a,int* sorted,int start,int mid,int end)
{
	
	//we divide the array into two parts,the letf array and the right array

	//the index of the left array
	int startL = start;
	int endL = mid;

	//the index of the right array
	int startR = mid + 1;
	int endR = end;

	//the index of the sorted array
	int index = start;


	while (startL <= endL&&startR <= endR)
	{
		if (a[startL] <= a[startR])
		{
			sorted[index++] = a[startL++];
		}
		else
		{
			sorted[index++] = a[startR++];
		}
	}
		

	//the elements left are meant to be larger,we just put it to the end of sorted array
	while (startL <= endL)
	{
		sorted[index++] = a[startL++];
	}

	while (startR <= endR)
	{
		sorted[index++] = a[startR++];
	}



	//then we move them into array a
	//then the array a is sorted 
	for (int i = start; i <= end; i++)
	{
		*(a + i) = *(sorted + i);
	}
	
}


//recusively call the merge_sort 
void merge_sort(int*a, int* sorted, int start,int end)
{
	if (start < end)
	{
		int mid = (end + start) / 2;
		merge_sort(a, sorted, start, mid);
		merge_sort(a, sorted, mid + 1, end);
		MERGE(a, sorted, start, mid, end);
	}
	
}


void merge_exam()
{
	int *a=new int[10000];
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		a[i] = rand() % 10000;
	}
	int* sorted=new int[10000];
	

	clock_t start = clock();
	merge_sort(a, sorted, 0,9999);
	clock_t end = clock();
	delete[] sorted;
	for (int i = 0; i < 10000; i++)
	{
		cout << a[i] << endl;
	}

	cout << "the total time used of merge sort is " << end - start << " ms" << endl;
}
