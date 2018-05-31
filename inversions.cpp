#include<iostream>
using namespace std;

//find out all the inversions in an array
void MERGE(int* a, int* sorted, int start, int mid, int end,int& count)
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
			//element indexed from startL to endL is greater than element indexed startR 
			for (int i = startL; i <= endL; i++)
			{
				//print the inversion item
				count++;
				cout << "{" << a[i] << "," << a[startR] <<"}"<< endl;
			}
			sorted[index++] = a[startR++];

		}
	}

	while (startL <= endL)
	{
		sorted[index++] = a[startL++];
	}

	while (startR <= endR)
	{
		sorted[index++] = a[startR++];
	}


	for (int i = start; i <= end; i++)
	{
		*(a + i) = *(sorted + i);
	}

}



//recusively call the merge_sort 
void merge_sort(int*a, int* sorted, int start, int end,int& count)
{
	if (start < end)
	{
		int mid = (end + start) / 2;
		merge_sort(a, sorted, start, mid,count);
		merge_sort(a, sorted, mid + 1, end,count);
		MERGE(a, sorted, start, mid, end,count);
	}

}


void invertions_demo()
{
	int a[10] = {2,3,1,5,4,6,8,7,10,6};

	int count = 0;

	int* sorted = new int[10];

	cout << "the inversions are :" << endl;
	clock_t start = clock();
	merge_sort(a, sorted, 0,9,count);
	clock_t end = clock();
	delete[] sorted;
	
	cout << " the total inversion amount is " << count << endl;
}
