#include<iostream>
using namespace std;

int binary_search(int* a,int target,int n)
{
	int low = 0;
	int high = n;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (a[mid] == target)
		{
			return mid;
		}
		else if (a[mid] < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	return -1;
}


void binary_search_demo()
{
	const int TARGET = 90;
	int a[10] = {1,2,3,44,55,77,88,90,102,555};
	int index = binary_search(a, TARGET, 9);
	if (index == -1)
	{
		cout << "target not found" << endl;
	}
	
	cout << "target " << TARGET << " found at index " << index << endl;
}
