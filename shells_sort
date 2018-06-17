#include<iostream>
#include<time.h>
using namespace std;
void shells_sort(int* a, int n)
{
	int d = n;
	while (true)
	{
		d = d / 2;

		for (int i = 0; i < d; i++)
		{
			for (int j = i + d; j < n; j++)
			{
				//we got the first element
				int e = j - d;

				//the element to be inserted 
				int temp = a[j];

				//the gap between two array is d
				//got the a[e-d] until we touch the bottom 
				while (e >= 0 && temp < a[e])
				{
					a[e + d] = a[e];
					e -= d;
				}
				//insert temp to the right position
				a[e + d] = temp;
			}
		}

		//if d equals to 1,break
		if (d == 1)
		{
			break;
		}
	}
}


void shells_sort_demo()
{
	srand((unsigned int)time(NULL));
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 20;
	}
	shells_sort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << endl;
	}
}
