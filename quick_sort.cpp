#include<iostream>
using namespace std;
#include<time.h>
 /*
 * divide the array into two part 
 * take a[r] as the pivot 
 * the elements left side are less than a[r]
 * thus the right size greater
 * params p,the start index of the array input  r,the end index 
 */
int partion(int *a, int p,int r)
{
	int x = a[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (a[j] <= x)
		{
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	int temp = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp;
	return i + 1;
}


void quick_sort(int* a, int p, int r)
{
	if (p < r)
	{
		int q = partion(a, p, r);
		quick_sort(a, p, q - 1);
		quick_sort(a, q + 1, r);
	}
}

void quick_sort_demo()
{
	int a[20];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 20; i++)
	{
		a[i] = rand() % 50;
	}

	quick_sort(a, 0, 19);

	for (int i = 0; i < 20; i++)
	{
		cout << a[i] << endl;
	}
}
