#include<iostream>
using namespace std;

/*
* find out the max sum of an subarray 
*/

int  find_crossing(int*a, int start, int end)
{
	int sum = 0;
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int mid = (start + end) / 2;
	for (int i = mid; i >= start; i--)
	{
		sum += a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
		}
	}

	sum = 0;
	for (int i = mid + 1; i <= end; i++)
	{
		sum += a[i];
		if(sum>right_sum)
		{ 
			right_sum = sum;
		}
	}

	 return left_sum + right_sum;
}


int find_max_subarray(int* a, int start, int end)
{
	int left_sum, right_sum, cross_sum;
	if (start == end)
	{
		return a[start];
	}
	else
	{
		int mid = (start + end) / 2;
		left_sum=find_max_subarray(a, start,mid);
		right_sum = find_max_subarray(a, mid + 1, end);
		cross_sum = find_crossing(a, start, end);
		if (left_sum > right_sum&&left_sum > cross_sum)
		{
			return left_sum;
		}
		else if (right_sum >= left_sum&&right_sum >= cross_sum)
		{
			return right_sum;
		}
		else if (cross_sum >= left_sum&&cross_sum >= right_sum)
		{
			return cross_sum;
		}

	}
}
void max_subarray()
{
	int a[] = {2,-4,-2,1,4,5};
	int max = find_max_subarray(a, 0, 5);
	cout << "the maxium sum is " << max << endl;
}
