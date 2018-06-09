#include<iostream>
#include<time.h>
using namespace std;

class matrix
{

	int size_x, size_y;

	//the data source of this matrix 
	int** data;

public: 
	//default constructor of matrix
	matrix(int size_x,int size_y)
	{
		this->size_x = size_x;
		this->size_y = size_y;

		this->data = new int*[size_y];
		for (int i = 0; i < size_y; i++)
		{
			this->data[i] = new int[size_x];
		}
		for (int i = 0; i <size_y; i++)
		{
			for (int j = 0; j < size_x; j++)
			{
				data[i][j] = 0;
			}
		}
	}

	matrix(int size_x,int size_y, int** data)
	{
		this->data = data;
		this->size_x = size_x;
		this->size_y = size_y;
		//this->data = new int*[size_x];
	}


	
	void setDataSets(int** data)
	{
		this->data = data;
	}

	int sizeX()
	{
		return size_x;
	}

	int sizeY()
	{
		return size_y;
	}

	/*
	 * print the matrix to the console
	 */
	void printMetrix()
	{
		for (int i = 0; i <size_y; i++)
		{
			for (int j = 0; j < size_x; j++)
			{
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}

	matrix operator+(matrix b)
	{
		matrix* result = new matrix(size_x,size_y);
		for (int i = 0; i < size_y; i++)
		{
			for (int j = 0; j < size_x; j++)
			{
				result->data[i][j] = data[i][j] + b.data[i][j];
			}
		}
		return *result;
	}


	/*
	*	plus two matrixes
	*/
	matrix operator-(matrix b)
	{
		matrix* result = new matrix(size_x,size_y);
		for (int i = 0; i < size_y; i++)
		{
			for (int j = 0; j < size_x; j++)
			{
				result->data[i][j] = data[i][j] - b.data[i][j];
			}
		}
		return *result;
	}


	/*
	*  mutiple two matrixes 
	*/
	matrix operator*(matrix b)
	{
		
		matrix* result=new matrix(b.size_x,size_y);
		for (int i = 0; i < size_y; i++)
		{
			for (int j = 0; j < size_x; j++)
			{
				int s=0;
				for (int k = 0; k < size_x;k++)
				{
					s += data[i][k] * b.data[k][j];
				}
				result->data[i][j] = s;
			}
		}
		return *result;
	}


	/*
	*  return  a sub matrix of this matrix 
	*  params size_x size_y ,the size of the sub matrix 
	*/
	matrix subMatrix(int start_x, int start_y,int size_x,int size_y)
	{
		matrix* result = new matrix(size_x, size_y);
		for (int i = 0; i < size_y; i++)
		{
			for (int j = 0; j < size_x; j++)
			{
				result->data[i][j] = data[start_y + i][start_x + j];
			}
		}
		return *result;
	}


	
	
};



void   strassen(matrix A, matrix B)
{

	int mid_x_a = A.sizeX() / 2;
	int mid_y_a = A.sizeY() / 2;
	int mid_x_b = B.sizeX() / 2;
	int mid_y_b = B.sizeY() / 2;

	
	matrix a11 = A.subMatrix(0, 0, mid_x_a, mid_y_a);
	matrix a12 = A.subMatrix(mid_x_a, 0, A.sizeX() - mid_x_a, mid_y_a);
	matrix a21 = A.subMatrix(0, mid_y_a, mid_x_a, A.sizeY() - mid_y_a);
	matrix a22 = A.subMatrix(mid_x_a, mid_y_a, A.sizeX() - mid_x_a, A.sizeY() - mid_y_a);

	matrix b11 = B.subMatrix(0, 0, mid_x_b, mid_y_b);
	matrix b12 = B.subMatrix(mid_x_b, 0, B.sizeX() - mid_x_b, mid_y_b);
	matrix b21 = B.subMatrix(0, mid_y_b, mid_y_b, B.sizeY() - mid_y_b);
	matrix b22 = B.subMatrix(mid_x_b, mid_y_b, B.sizeX() - mid_x_b, B.sizeY() - mid_y_b);

	matrix s1 = b12 - b22;
	matrix s2 = a11 + a12;
	matrix s3 = a21 + a22;
	matrix s4 = b21 - b11;
	matrix s5 = a11 + a22;
	matrix s6 = b11 + b22;
	matrix s7 = a12 - a22;
	matrix s8 = b21 + b22;
	matrix s9 = a11 - a21;
	matrix s10 = b11 + b12;

	

	matrix p1 = a11*s1;
	matrix p2 = s2*b22;
	matrix p3 = s3*b11;
	
	matrix p4 = a22*s4;
	matrix p5 = s5*s6;
	matrix p6 = s7*s8;
	matrix p7 = s9*s10;

	matrix c11 = p5 + p4 - p2 + p6;
	matrix c12 = p1 + p2;
	matrix c21 = p3 + p4;
	matrix c22 = p5 + p1 - p3 - p7;
	
	cout << "c11 " << endl;
	c11.printMetrix();
	cout << endl;

	cout << "c12" << endl;
	c12.printMetrix();
	cout << endl;

	cout << "c21" << endl;
	c21.printMetrix();
	cout << endl;

	cout << "c22" << endl;
	c22.printMetrix();
	cout << endl;

}

void strassen_demo()
{
	srand((unsigned int)time(NULL));
	int** a = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		a[i] = new int[4];
		for (int j = 0; j < 4; j++)
		{
			a[i][j] = rand() % 20;
		}
	}
	
	
	int** b = new int*[3];
	for (int i = 0; i < 4; i++)
	{
		b[i] = new int[4];
		for (int j = 0; j < 4; j++)
		{
			b[i][j] = rand() % 20;
		}
	}

	cout << "the original matrixes :";
	matrix* A = new matrix(4, 4);
	A->setDataSets(a);
	A->printMetrix();
	
	cout << endl;
	matrix* B = new matrix(4, 4);
	B->setDataSets(b);

	B->printMetrix();
	cout << endl;
	strassen(*A, *B);

}
