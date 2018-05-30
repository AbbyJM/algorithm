#include<iostream>
#include<time.h>
using namespace std;
//bubble sort algorithm
void bubble_sort(int* a,int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = n - 1; j >= i + 1; j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

void bubble_sort_demo()
{
	int* a = new int[10000];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		a[i] = rand() % 10000;
	}

	clock_t start = clock();
	bubble_sort(a, 10000);
	clock_t end = clock();


	for (int i = 0; i < 10000; i++)
	{
		cout << a[i] << endl;
	}
	

	cout << "time used is " << end - start << " ms" << endl;
}
