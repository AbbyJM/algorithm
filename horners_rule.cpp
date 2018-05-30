
#include<iostream>
using namespace std;

/*
 *  param a,the array of coefficients
 *  param n,the count of the coefficients,from 0 to length-1
 *  param x
 */
int horner(int *a, int n, int x) 
{
	int ax = a[n] * x + a[n - 1]; 
	
	//index n and n-1 is taken,so we start with n-2 here 
	for (int i = n - 2; i >= 0; i--)   
	{
		ax = ax * x + a[i];
	}
	return ax;
}

//the naive polynominal evaluating
int naive_poly_eval(int* a,int n,int x)
{
	int result = 0;
	
	//i is the power 
	for (int i = 0; i <= n; i++)
	{
		int m = 1;
		//for example,if i equals to 2,we got x*x
		for (int n = 1; n <= i; n++)
		{
			m = m*x;
		}
		
		result = result + a[i] * m;
	}
	return result;
}

void horner_demo()
{
	int a[] = { 4,5,77,55,6,0 }; 
	cout << "using naive polynomial evaluating: " << endl;
	cout << naive_poly_eval(a, (sizeof(a)/sizeof(int)-1), 2) << endl;

	cout << "using the horner's rule: " << endl;
	cout << horner(a, (sizeof(a)/sizeof(int)-1), 2) << endl;
}

