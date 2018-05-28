#include<iostream>
#include<time.h>
using namespace std;
//the insertion sort algorithm


/*
 * param a ,the array to be sorted
 * param n ,the size of the array
 */
void insertion_sort(int* a,int n)
{
	for (int i = 1; i <= n-1; i++)
	{
		int key = a[i];
		int j = i-1;
		while (j >= 0 && a[j] > key) 
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void insertion_sort_exam()
{
	int a[10000];
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		a[i] = rand() % 10000;
	}


	clock_t start = clock();

	insertion_sort(a, sizeof(a) / sizeof(int));

	clock_t end = clock();
	cout << "the sorted array: " << endl;
	for (int i = 0; i < 10000; i++)
	{
		cout << a[i] << endl;
	}

	cout << "total time used of insertion sort is " << end-start <<" ms "<<endl;
}
